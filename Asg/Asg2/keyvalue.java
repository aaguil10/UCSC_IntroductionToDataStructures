// $Id: keyvalue.java,v 1.2 2012-10-16 18:21:51-07 - - $
//Pair programing Alejandro Aguilar (aaguil10@ucsc.edu) 
// and Alessio Alba (acalba@ucsc.edu) 
import java.io.*;
import java.util.Iterator;
import static java.lang.System.*;
import java.util.Scanner;

class keyvalue {

public static void main (String[] args) {

linkedlist list = new linkedlist();
if(args.length < 1){
err.println("Needs An Argument");
}else{
 for (int i = 0; i < args.length; ++i) {
 if (args[i].equals("-")) {
  scanfile (new Scanner (in), "<stdin>",list);
 }else {
     try {
    String filename = args[i];
    Scanner input = new Scanner (new File(filename));
    scanfile (input, filename, list);
    input.close();
   }catch (IOException error) {
    messages.warn (error.getMessage());
   }
  }
 }
}
exit (messages.exit_status);
}
static void scanfile (Scanner input, String filename,linkedlist list) {
 while (input.hasNextLine()) {
 String line = input.nextLine();
 if (!line.contains("#")){
 line  = line.trim();
 if (line.contains("=")){
   String[] parts = line.split("=",2);
   parts[0].trim();
   parts[1].trim();
//if they both have values
   if (parts[0] != null){
     if (parts[1] != null){
      list.put(parts[0],parts[1]);
list.printKeyValue();
     }
     if (parts[1]== null){
      list.getKey(parts[0]);
      list.delete(parts[0]);
     }
  }
//is they just typed =blah 
   if (parts[1]!= null && parts[0]==null){
       list.getKey(parts[1]);
     

   }
//if they just typed an =
   if (parts[0]== "\n" && parts[1]== "\n"){
list.printList();
//       for(pair p: list){
//System.out.println("n");
//       System.out.printf(" %s = %s", p.key,p.value);
//     }
   }
 }
     else{
       list.getKey(line);
     }
 }
 }    
}
}




