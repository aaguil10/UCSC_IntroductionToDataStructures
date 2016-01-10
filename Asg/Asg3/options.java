// $Id: options.java,v 1.1 2012-10-31 13:12:50-07 - - $

class options {
boolean count_only = false;
boolean dump_tree = false;
boolean fold_cases = false;
String[] filenames = null;

	options (String[] args) {
                if(args[0].startsWith("-")){
                        for(int optPos = 1; optPos < args[0].length(); optPos++){
                                switch(args[0].charAt(optPos)){
                                case 'c':count_only = true;
                                case 'd':dump_tree = true;
                                case 'f':fold_cases = true;
                                break;
                                }
			}
		if(args.length > 0){
		String[] filenames = new String[args.length-1];
        	for(int k = 1;k < filenames.length;k++){
        		filenames[k] = args[k];
		}
                }else{
			System.out.println("need more args bro.");
		}
		}
	}

}
