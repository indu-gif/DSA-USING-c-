#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void Enqueue();
void Dequeue();
void display();
int items[5];
int n = 5, rear = -1, front =-1,value;
int x;

int main()
{
	int choice;
    int k;
    do
    {
        printf("\n 1. Enqueue \n 2. Dequeue \n 3. display \n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        switch (choice)
        {
        	case 1:
			printf("Enter element ");
			scanf("%d",&x);
			Enqueue(x);
        	       break;
            case 2:Dequeue();
                   break;
            case 3:display();
                   break;
                   
            default: printf("Invalid operation !!");
		}
		printf("\nDo you want to continue ? =\n");
        scanf("%d",&k);
    } 
    while(k==1);
    
    return 0;
}

void Enqueue(int value)
{
	if(rear == n-1)
	{
	printf("Queue is full !!");
	getch();
	exit(0);
    }
	if(front==-1)
	{
		front = 0;
	}
	rear++;
	items[rear] = value;
			
}
void Dequeue()
{
    if (front == rear + 1) {
        printf("Queue is Empty");
        getch();
    	exit(0);
    }
    else 
    {
    
    	int x = items[front];
    	printf("Dequeued element is = %d",x);
    	front++;
	}
      
}

void display()
{
	int i;
	for(i = front;i<=rear;i++)
	{
	printf("%d",items[i]);	
	}
}