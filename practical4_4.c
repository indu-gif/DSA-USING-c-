#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack {
 char ch;
 struct stack *next;
};
struct stack *top = NULL;

int checkExp(char[]);
void infixToPostfix(char[]);
int isopr(char);
int isopd(char);
int iprec(char);
int sprec(char);
void push(char);
char pop();
int evaluatePostfix(char []);


int main() {
 char x[80];
 printf("Enter the String : ");
 gets(x);
 if(checkExp(x)) {
  infixToPostfix(x);
        int result = evaluatePostfix(x);
        printf("Result: %d\n", result);
 } 
 else {
  printf("Invalid Expression\n");
 }
 
return 0;
}

int iprec(char m) {
 switch(m) {
  case '+' : case '-' :
	return 2;
  case '*' : case '/' : case '%' :
	return 4;
  case '^' :
	return 6;
  case '(' :
	return 8;
  default :
	return -1;
 }
}

int sprec(char m) {
 switch(m) {
  case '+' : case '-' :
	return 2;
  case '*' : case '/' : case '%' :
	return 4;
  case '^' :
	return 6;
  case '(' :
	return 1;
  default :
	return -1;
 }
}

int isopd(char m) {
 if((m>='a' && m<='z') || (m>='A' && m<='Z') || (m>='0' && m<='9')) {
  return 1;
 } else {
  return 0;
 }
}

int isopr(char m) {
 if(m=='+' || m=='-' || m=='*' || m=='/' || m=='^') {
  return 1;
 } else {
  return 0;
 }
}

void push(char m) {
 struct stack *p = (struct stack *)malloc(sizeof(struct stack));
 p->ch = m;
 p->next = top;
 top = p;
}

char pop() {
  struct stack* p;
    char data; 

    if (top != NULL) {
        p = top;
        top = top->next;
        data = p->ch; 
        free(p);
        return data;
}
}


int checkExp(char x[80]) {
 int i,n;
 n = strlen(x);

 for(i=0;i<n-1;i++) {
  if((isopd(x[i]) && isopd(x[i+1])) || (isopr(x[i]) && isopr(x[i+1])) || (isopr(x[i]) && x[i+1]==')') || (x[i]=='(' && isopr(x[i+1]))) {
   return 0;
  }
 }

 return 1;
}

void infixToPostfix(char x[80]) {
 char y[80];
 int i,n,k=0;
 n = strlen(x);

 for(i=0;i<n;i++) {
  if(isopd(x[i])) {
   y[k++]=x[i];
  }
  else if(x[i]=='(') {
   push(x[i]);
  }
  else if(x[i]==')') {
   while(top->ch!='(')
    y[k++] = pop();
   pop();
  }
  else if(isopr(x[i])) {
   while(sprec(top->ch)>=iprec(x[i]))
    y[k++]=pop();
   push(x[i]);
  }
 }

 while(top!=NULL) {
  y[k++]=pop();
 }

 y[i]='\0';

 printf("Postfix Expression:");
puts(y);
}

int evaluatePostfix(char expression[80]) {
   

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isopd(expression[i])) {
            push( expression[i] - '0'); 
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int operand2 = pop();
            int operand1 = pop();
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }

    return pop(); 
}
