//Alejandro Aguilar aaguil10@ucsc.edu

#include <errno.h>
#include <libgen.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *progname = NULL; // Name of the program being run.
int exit_status = EXIT_SUCCESS; // Assume successful completion.

struct options { // Structure to hold options.
	bool moretitles; // Print titles in more-style
	bool numberlines; // Output line numbers for each line.
	bool squeeze; // Squeeze multiple empty lines.
};

void catfile (FILE *input, char *filename, struct options *opts) {
	char buffer[4096];
	for (;;) {
		char *bufrc = fgets (buffer, sizeof buffer, input);
		if (bufrc == NULL) break;
			printf ("%s", buffer);
	};
}	

void scan_options (int argc, char **argv, struct options *opts) {
	memset (opts, 0, sizeof (struct options));
	opterr = false;
	(opts*).moretitles = 0;
	(opts*).numberlines = 0;
	(opts*).squeeze = 0;
	for (;;) {
		int opt = getopt (argc, argv, "mns");
		if (opt == EOF) break;
		switch (opt) {
			case 'm':
			opts->moretitles = 1;
			break;
			case 'n':
			opts->numberlines = 1;
			break;
			case 's':
			opts->squeeze = 1;
			break;
			default :
			fflush (NULL);
			fprintf (stderr, "%s: -%c: invalid option\n",progname, optopt);
			fflush (NULL);
			exit_status = EXIT_FAILURE;
		}
	}
	if(nuberlines == 1 && squeeze == 1){
	 while(buffer[i] != null){
                        if(buffer[i] == "\n" && buffer[p] != "\n"){
				c++;
				printf("%d. %s",c,buffer[i]);
                                p++;
                                i++;
                        }
                        if(buffer[i] == "\n" && buffer[p] == "\n"){
                                i++;
                                p++;
                        }
                        if(buffer[i] != "\n"){
                        c++;
			printf("%d. %s",c,buffer[i]);
                        i++;
                        p++;
                        }
                }

	}

	if(moretitles == 1){
		printf("\n");
		char col[] = "::";
		int i;
		for(i = 0;i<64;i++){
			printf("%s",col);
		}
		printf("%s",progname);
		i = 0;
		for(i = 0;i<64;i++){
	                printf("%s",col);
	        }
		printf("\n");
	}

	if(numberlines == 1){
		int c = 0;
		while(buffer[c] != null){
		c++;
		}
	c++;
	printf("%6d  %s",c,buffer);	
	}
	if(squeeze == 1){
		int i = 0;
		int c = 0;
		int p = c-1;
		while(buffer[i] != null){
			if(buffer[i] == "\n" && buffer[p] != "\n"){
				c++;
				p++;
				i++;
			}
			if(buffer[i] == "\n" && buffer[p] == "\n"){
				i++;
				p++;
			}
			if(buffer[i] != "\n"){
			c++;
			i++;
			p++;
			}
		}

	}


}

int main (int argc, char **argv) {
	exit_status = EXIT_SUCCESS;
	progname = basename (argv[0]);
	struct options opts;
	scan_options (argc, argv, &opts);
	if (optind == argc) {
		catfile (stdin, "-", &opts);
	}else{
		for (int argi = optind; argi < argc; ++argi) {
			char *filename = argv[argi];
				if (strcmp (filename, "-") == 0) {
					catfile (stdin, "-", &opts);
				}else{
					FILE *input = fopen (filename, "r");
					if (input == NULL) {
						fflush (NULL);
						fprintf (stderr, "%s: %s: %s\n", progname,argv[argi], strerror (errno));fflush (NULL);
						exit_status = EXIT_FAILURE;
					}else{
						catfile (input, filename, &opts);fclose (input);
					};
				};
		};
	};
	return exit_status;
}
