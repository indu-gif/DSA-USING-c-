#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Enqueue(int);
void Dequeue();
void Display();
int queue[5];
int front=-1,rear=-1,max=5;

int main() {
 int choice,ch,x;
 do {
  printf("1. Enqueue()\n2. Dequeue()\n3. Display()\n");
  printf("Enter your Choice : ");
  scanf("%d",&choice);

  switch(choice) {
   case 1 : printf("Enter element you want to enqueue : ");
	    scanf("%d",&x);
	    Enqueue(x); break;
   case 2 : Dequeue(); break;
   case 3 : Display(); break;
   default : printf("Invalid Choice\n");
  }

  printf("Do you want to Continue? (1 for Yes):-");
  scanf("%d",&ch);
 } while(ch==1);
 getch();
 return 0;
}

void Enqueue(int x) {
 if(front==-1 && rear==-1) {
  front=rear=0;
  queue[rear]=x;
 }
 else if((rear+1)%max==front) {
  printf("Queue is Overflow\n");
  getch();
  
 }
 else {
  rear=(rear+1)%max;
  queue[rear]=x;
 }
 printf("Enqueue() done for : %d\n",x);
}

void Dequeue() {
 if(front==-1 && rear==-1) {
  printf("Queue is Underflow\n");
  getch();
  exit(0);
 }
 else if(front==rear) {
  front=rear=-1;
 }
 else {
  printf("Dequeue() Done for : %d\n",queue[front]);
  front=(front+1)%max;
 }
}

void Display() {
 int i;
 for(i=0;i<max;i++) {
  printf("%d\t",queue[i]);
 }
 printf("\nDisplay() Done\n");
}