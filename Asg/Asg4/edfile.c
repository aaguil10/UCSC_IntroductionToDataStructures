// $Id: edfile.c,v 1.22 2012-11-27 08:00:14-08 - - $

#include <assert.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "debugf.h"
#include "list.h"

bool want_echo = false;

void badline (int stdincount, char *stdinline) {
   fflush (NULL);
   fprintf (stderr, "Bad input line %d: %s\n", stdincount, stdinline);
   fflush (NULL);
}

void editfile (list_ref list) {
   char stdinline[1024];
   int stdincount = 0;
   for(;; ++stdincount) {
      printf ("%s: ", Exec_Name);
      char *linepos = fgets (stdinline, sizeof stdinline, stdin);
      if (linepos == NULL) break;
      if (want_echo) printf ("%s", stdinline);
      linepos = strchr (stdinline, '\n');
      if (linepos == NULL || stdinline[0] == '\0') {
         badline (stdincount, stdinline);
      }else {
         *linepos = '\0';
         switch (stdinline[0]) {
            case '$': dollarsign(list); break;
            case '*': starsign(list); break;
            case '.': dotsign(list); break;
            case '0': zerosign(list); break;
            case '<': lessthansign(list); break;
            case '>': morethansign(list); break;
            case '@': debugdump_list (list); break;
            case 'a': a_sign(list,stdinline); break;
            case 'd': d_sign(list); break;
            case 'i': i_sign(list,stdinline); break;
            case 'r': STUBPRINTF ("stdin[%d]: r\n", stdincount); break;
            case 'w': w_sign(list,stdinline); break;
            case 't': tester(list,stdinline); break;
            default : badline (stdincount, stdinline);
         }
      }
   }
}

void dollarsign(list_ref list){
   setmove_list(list,MOVE_LAST);
}
void starsign(list_ref list){
   viewcurr_list(list);
   setmove_list(list,MOVE_LAST);
}
void dotsign(list_ref list){
   printcurrln(list);
}
void zerosign(list_ref list){
   setmove_list(list,MOVE_HEAD);
}
void lessthansign(list_ref list){
   setmove_list(list,MOVE_PREV);
   printcurrln(list);
}
void morethansign(list_ref list){
   setmove_list(list,MOVE_NEXT);
   printcurrln(list);
}
void a_sign(list_ref list,char *line){
   setopt_list(list,A_OPT,line);
   printcurrln(list);
}
void i_sign(list_ref list,char *line){
   setopt_list(list,I_OPT,line);
   printcurrln(list);
}
void d_sign(list_ref list){
   deletenode(list);
}
void w_sign(list_ref list,char *name){
   print_file(list,name);
}


void usage_exit() {
   fflush (NULL);
   fprintf (stderr, "Usage: %s filename\n", Exec_Name);
   fflush (NULL);
   exit (EXIT_FAILURE);
}

int main (int argc, char **argv) {
   Exec_Name = basename (argv[0]);
   if (argc != 2) usage_exit();
   want_echo = ! (isatty (fileno (stdin)) && isatty (fileno (stdout)));
   list_ref list = new_list();
   editfile (list);
   free_list (list); list = NULL;
   return Exit_Status;
}

void tester(list_ref list,char *line){
printf("Testing testing 1,2...3 Testing Testing.\n");
insert_list(list,line);
//char *currentline = viewcurr_list(list);

}
