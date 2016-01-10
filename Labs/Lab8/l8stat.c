//Aleja       #include <sys/types.h>
//       #include <sys/stat.h>
//       ndro Aguilar aaguil10@ucsc.edu
//ddfgh
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <time.h>
       #include <stdio.h>
       #include <stdlib.h>

       
       int main(int argc, char *argv[]){
           struct stat sb;

           if (argc != 2) {
               int noOpt = lstat(., &sb);
               printf("%b %e %R",noOpt);
               exit(EXIT_FAILURE);
           }

           if (stat(argv[1], &sb) == -1) {
               perror("stat");
               if(sb.st_mtime < sb.st_atime - sb.st_ctime){
               int bar = lstat(this-is-a-symlink, &sb);
               printf("%b %e %R",bar);

               }
               
               if(sb.st_atime + sb.st_ctime < sb.st_mtime){
               int foo = lstat(this-is-a-symlink, &sb);
               printf("%b %e %R",foo);


               }


               exit(EXIT_SUCCESS);
           }




           printf("Mode:                     %lo (octal)\n",
                   (unsigned long) sb.st_mode);

           printf("Link count:               %ld\n", (long) sb.st_nlink);

           printf("File size:                %lld bytes\n",
                   (long long) sb.st_size);

           printf("Last status change:       %s", ctime(&sb.st_ctime));
           printf("Last file access:         %s", ctime(&sb.st_atime));
           printf("Last file modification:   %s", ctime(&sb.st_mtime));

           exit(EXIT_SUCCESS);
       }
