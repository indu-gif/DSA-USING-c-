// abdcdba : WCWr

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
  char ch;
  struct stack *next;
};
struct stack *top = NULL;

void push(char);
char pop();
int execute(char[]);


int main() {
 char x[80];
 int ans;

 printf("Enter your String : ");
 gets(x);

 ans = execute(x);

 if(ans == 0) {
  printf("String doesn't Follow WCWr\n");
 } else {
  printf("String Follow WCWr\n");
 }


 return 0;
}

int execute(char y[80]) {
 int i=0;
 char k;
 while(y[i]!='c' && y[i]!='C') {
  push(y[i]);
  i++;
 }
 i++;
 while(y[i]!='\0') {
  k = pop();
  if(y[i]==k) {
   i++;
  } else {
   return 0;
  }
 }
 if(top != NULL) {
  return 0;
 } else {
  return 1;
 }
}

void push(char m) {
 struct stack *p = (struct stack *)malloc(sizeof(struct stack));
 p->ch = m;
 p->next = top;
 top = p;
}

char pop() {
 struct stack *p;
 if(top!=NULL) {
  p = top;
  top = top->next;
 }
 return p->ch;
}