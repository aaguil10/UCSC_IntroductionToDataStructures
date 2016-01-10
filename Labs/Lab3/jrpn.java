//Alejandro Agilar aaguil10
import java.util.Scanner;
import static java.lang.System.*;

class jrpn{

final int EMPTY = -1;
static int top = EMPTY;
double[] stack = new double[16];

public static void main(String args[]){
Scanner stdin = new Scanner(system.in);
while(stdin.hasNext()){
String word = stdin.next();
//skips # comment
if(word == '#'){
word  = stdin.nextline();
}else{
//sets vaules for stack
switch(word){


case '+': addStack(); break;
case '-': subStack(); break;
case '*': mutlStack(); break;
case '/': divStack(); break;
case ';': printStack(); break;
case '~': clearStack(); break;
//case "Integer": putIntinArry(); break;



}

}

}
}
//create a switch stament to read - + * /

static void push(int num){
top++;
stack[top] = num;
}

static void putIntinArray(int num){
stack[top] = num;
top++;
}

static void addStack(){
stack[0] + stack[1] = stack[0];
}

static void subStack(){
stack[0] - args[1] = stack[0];
}

static void mutlStack(){
stack[0] * stack[1] = stack[0];
}

static void divStack(){
stack[0] / stack[1] = stack[0];
}

static void printStack(){
for(int i = 0; i < stack.length;i++){
System.out.println(stack[i]);
}
}
static void clearStack(){
for(int k = 0; k > stack.length;k++){
stack[k] = null;
}
}


}
