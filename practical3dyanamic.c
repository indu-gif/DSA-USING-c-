#include <stdio.h>
#include <stdlib.h>
struct stack {
    int data;
    struct stack *next;
}*top=NULL;
    
typedef struct stack st;
void push();
int pop();
void traverse();
//void peep();
void isempty();
void isfull();
//void change();

int main(){
    int choice;
    int k;
    do
    {
        printf("\n 1. PUSH\n 2. POP \n 3. traverse \n 4. peep \n 5. isempty \n 6. isfull \n 7. change");
        
        printf("\nenter your choice :  ");
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

        // case 4: peep();
        // printf("peep done\n");
        // break; 

        case 5: isempty();
        printf("is empty done ");
        break;

        case 6:isfull();
        printf("isfull done");
        break;
         
        //  case 7:change();
        //  printf("\nchange is done\n");
        //  break;
        default:
            printf("Did you Entered right choice ?");
        }
printf("Do you want to continue ? =");
scanf("%d",&k);
    }while(k==1);
    
    
}

void push(){
st *p;
p=(st *)malloc(sizeof(st));
printf("Enter element= ");
scanf("%d",&p->data);
p->next=top;
top=p;
printf("%d",p->data);
}

int pop(){
   st *p;
p=(st *)malloc(sizeof(st));
p=top;
if (top==NULL)
{
printf("Stack is underflow\n");
}

else{
top=p->next;
free(p);
    }
    return p->data;
}


void traverse(){
    st *p;
p=(st *)malloc(sizeof(st));
    p=top;
if (top==NULL)
{
printf("Stack is underflow");
}
else{
    while (p->next!=NULL)
    {
    printf("%d\n",p->data);
    p=p->next;
        }
    printf("%d\n",p->data);
}

}
void isempty(){
    st *p;
p=(st *)malloc(sizeof(st));
p=top;
if (top==NULL)
{
printf("\nStack is underflow");
}
}

void isfull(){
    st *p;
p=(st *)malloc(sizeof(st));
p=top;
if (top!=NULL)
{
printf("\nStack is overflow\n");
}
}