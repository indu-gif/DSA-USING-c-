#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack {
    char data;
    struct stack *next;
}*top=NULL;
    
typedef struct stack st;
int execute(char[]);
int opd(char);
int  opr(char);
int matchpair(char,char);
char pop();
void push();
int  main(){
    
    char x[80];
    printf("ENTER string = ");
    gets(x);
    int ans=execute(x);

    if (ans== 1) {
        printf("The expression '%s' is valid.\n", x);
    } else {
        printf("The expression '%s' is not valid.\n", x);
    }


}

int execute(char x[]){
int n;
int i=0;
n = strlen(x);

for(i=0;i<n-1;i++){
if (opd(x[i]) && opd(x[i+1])||opr(x[i])&& opr(x[i+1]))
{
    return 0;
}


else if(x[i]=='('|| x[i]=='['|| x[i]=='{') {

    

        void push(char m){
st *p=(st *)malloc(sizeof(st));
p->data=m;
p->next=top;
top=p;

        }
    
}



else if(x[i]==')'|| x[i]==']'|| x[i]=='}'){
   
char popped = pop(); 
            if (!matchpair(popped, x[i])) {
                return 0; 
                return 1;
            }

}}
if(top!=NULL){
    return 0;
}
return 1;
}




int opd(char m){

if ((m >='a' && m<= 'z')||(m >='A'&& m<= 'Z')||(m >= '0' && m<= '9'))
{
    return 1;
}

else{
    return 0;
}
}


int opr(char m){
   if(m =='+' || m =='-' || m =='*' || m =='/'){
    return 1;
   } 
   else{

    return 0;
   }
}

int matchpair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    return 0;
}

char pop(){
    st *p=(st *)malloc(sizeof(st));
    if(top==NULL){
        printf("stack is underflow");
    }
else{
    st* p= top;
    char data = top->data;
    top = top->next;
    free(p);
    return data;
}

}
