#include<stdio.h>
#include <stdlib.h>
void push();
int pop();
void traverse();
void peep();
void isempty();
void isfull();
void change();
int stack[10];
int top=-1,max=10;

int main(){
    int choice;
    int k;
    do
    {
        printf("\n 1. PUSH\n 2. POP \n 3.traverse \n 4.peep \n 5. isempty \n 6. isfull \n 7. change");
        
        printf("enter your choice :  ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : push();
        printf("\n push done \n");
        
            break;
        
        case 2:
        printf("\n pop done %d\n",pop());
        break;

        case 3: traverse();
        printf("Traverse done \n");
        break;

        case 4: peep();
        printf("peep done\n");
        break; 

        case 5: isempty();
        printf("is empty done ");
        break;

        case 6:isfull();
        printf("isfull done");
        break;
         
         case 7:change();
         printf("\nchange is done\n");
         break;
        default:
            printf("Did you Entered right choice ?");
        }
printf("Do you want to continue ? =");
scanf("%d",&k);
    } 
    while(k==1);
    
    
}

void push(){
    int item;
    if (top==max-1)
    {
        printf("\n stack is overflow ");

    }
    else{
        printf("\nEnter element=");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
        printf("Element pushed to stack");
    }
    
}

int pop(){
    int item;
    if(top== -1){
        printf("\n stack is empty");
        exit(0);
    }
    else{
        item=stack[top];
        top=top-1;
    }
    return item;
}

void traverse(){
int i;
if (top==-1)
{
    printf("\nstack is empty\n");
}

for ( i = top; i>=0 ; i--)
{
    printf("\n element is = %d\n",stack[i]);
}

}

void peep(){
    int a,temp;
    printf("\nEnter the position=\n");
    scanf("%d",&a);
    if(top-a+1<0){
        printf("\nstack is underflow\n");

        int temp=stack[top-a+1];
         printf("Element peeped to stack");
    }
    
}

void change(){
int a,x;
printf("\n Enter the position which you want to change = \n");
scanf("%d",&a);
printf(" \n Enter the value =\n");
scanf("%d",&x);
    if(top-a+1<0){
        printf("\n Stack is underflow \n");
        stack[top-a+1]=x;
         printf("Element changed to stack");
    }
}

void isempty(){
    if (top== -1)
    {
        printf("\nStack is empty");
    }
}
 
 void isfull(){
    if(top== max-1){
        printf("\nstack is full");
    }
 }