//options.java file
// $Id: options.java,v 1.2 2012-10-08 18:58:00-07 - - $
//Alejandro Aguilar aaguil10@ucsc.edu

class options {
	boolean insensitive = false;
	boolean filename_only = false;
	boolean number_lines = false;
	boolean reverse_match = false;
	String regex;
	String[] filenames;

	options (String[] args) {
		int c = 0;
//if the line starts with - it going to change the options to it's corresponding values
		if(args[c].startsWith("-")){
			for(int optPos = 1; optPos < args[0].length(); optPos++){
				switch(args[0].charAt(optPos)){
				case 'i':insensitive = true;
				case 'l':filename_only = true;
				case 'n':number_lines = true;
				case 'v':reverse_match = true;
				break;
				}
		c++;
		}
//args[1] is refering to the pattern which is set to regex then incremented by 1 
	regex = args[c++];
//turns the rest of the line into an array of filenames
	String[] filenames = new String[args.length-1];
	for(int k = 1;k < filenames.length;k++){
	filenames[k] = args[k];
	}
	} 

	}
}
