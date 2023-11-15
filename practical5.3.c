#include <stdio.h>
#include <stdlib.h>

void EnqueueF(int x);
void DequeueR();
void EnqueueR(int x);
void DequeueF();
void Display();
int queue[7];
int front = -1, rear = -1, max = 7;

int main()
{
    int choice, ch, x;
    do
    {
  printf("1. EnqueueR()\n2. DequeueF()\n
  3.EnqueueF()\n 4.DequeueR\n 5. Display()\n");
  printf("Enter your Choice : ");
  scanf("%d",&choice);

  
    switch(choice) {
        case 1:
            printf("Enter element you want to enqueue : ");
            scanf("%d", &x);
            EnqueueR(x);
            break;
        case 2:
            DequeueF();
            break;
        case 3:
            printf("Enter element you want to enqueue : ");
            scanf("%d", &x);
            EnqueueF(x);
            break;
        case 4:
            DequeueR();
            break;
        case 5:
            Display();
            break;
        default:
            printf("Invalid Choice\n");
  }

  printf("Do you want to Continue? (1 for Yes):-");
  scanf("%d",&ch);
    } while(ch == 1);
    
    return 0;
}

void DequeueR()
{
    if (front == -1 && rear == -1)
    {
  printf("under flow\n");
    }
    else if (front == rear)
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  front = rear = -1;
    }
    else if (rear == 0)
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  rear = max - 1;
    }
    else
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  rear = rear - 1;
    }
}
void DequeueF()
{
    if (front == -1 && rear == -1)
    {
  printf("under flow\n");
    }
    else if (front == rear)
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  front = rear = -1;
    }
    else if (front == max - 1)
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  front = 0;
    }
    else
    {
  printf("Dequeue() Done for : %d\n", queue[front]);
  front = front + 1;
    }
}

void EnqueueR(int x)
{
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
  printf("OVER FLOW");
    }
    else if (front == -1 && rear == -1)
    {
  front = rear = 0;
  queue[rear] = x;
    }
    else if (rear == max - 1)
    {
  rear = 0;
  queue[rear] = x;
    }
    else
    {
  rear = rear + 1;
  queue[rear] = x;
    }
}

void EnqueueF(int x)
{
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
  printf("OVER FLOW");
    }
    else if (front == -1 && rear == -1)
    {
  front = rear = 0;
  queue[front] = x;
    }
    else if (front == max - 1)
    {
  front = 0;
  queue[front] = x;
    }
    else
    {
  front = front + 1;
  queue[front] = x;
    }
}

void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
  printf("%d\t", queue[i]);
    }
    printf("\nDisplay() Done\n");
}