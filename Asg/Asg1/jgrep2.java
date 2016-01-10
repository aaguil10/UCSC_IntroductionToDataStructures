//Alejandro Aguilar aaguil10@ucsc.edu 
//My jgrep file
// $Id: jgrep.java,v 1.4 2012-10-08 18:58:27-07 - - $
//
// This program is a stub showing how to create a pattern from a
// regular expression. It does not handle options or files, and
// has some other bugs which you must discover and fix.
//

import java.io.*;
import java.util.Scanner;
import java.util.regex.*;
import static java.lang.System.*;

class jgrep { 
//reads file and seaches for matches
	static void scanfile (Scanner input, String filename, Pattern pattern) {
		while (input.hasNextLine()) {
			String line = input.nextLine();
			boolean matches = pattern.matcher (line).find();
			if (matches) {
			out.printf ("%s:%s%n", filename, line);
			}
		}	
	}
//reads options file and if no args are put it prints an error message
public static void main (String[] args) {
	options flags = new options (args);
	if (args.length == 0) {
		err.printf ("Usage: %s [-ilnv] regex [filename...]%n", messages.program_name);
		exit (messages.EXIT_FAILURE);
	}
//reads the file names that i intalize in options
try {
	Pattern pattern = Pattern.compile (flags.regex);
	if (args.length == 1) {
		scanfile (new Scanner (in), "<stdin>", pattern);
	}else {
		for (int argi = 1; argi < args.length; ++argi) {
		scanfile(new Scanner (flags.filenames[argi]), flags.filenames[argi], pattern);
			try {
				String filename = args[argi];
				Scanner input = new Scanner (new File (filename));
				scanfile (input, filename, pattern);
				input.close();
			}catch (IOException error) {
				messages.warn (error.getMessage());
			}
		}
	}
//if it fails it kills it
	}catch (PatternSyntaxException error) {
		messages.die (error.getMessage());
	}
	exit (messages.exit_status);
	}
}

