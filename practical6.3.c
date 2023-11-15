#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

void insertatfirst(int x);
void insertatend(int x);
void insertatposition(int item, int index);
void deleteatfirst();
void deleteatend();
// void deleteatposition(int index);
void display();

int main() {
    int choice = 0;
    int item, index;

    printf("Enter the operation number\n");
    printf("1.insertatfirst\n2.insertatend\n3.insertatposition\n4.deleteatfirst\n5.deleteatend\n6.deleteatposition\n7.display\n");
    printf("Enter your choice =\n");
    scanf("%d", &choice);

    while (choice != 8) {
        switch (choice) {
            case 1:
                printf("Enter element=");
                scanf("%d", &item);
                insertatfirst(item);
                break;

            case 2:
                printf("Enter element=");
                scanf("%d", &item);
                insertatend(item);
                break;

            case 3:
                printf("Enter element=");
                scanf("%d", &item);
                printf("Enter position=");
                scanf("%d", &index);
                insertatposition(item, index);
                break;

            case 4:
                deleteatfirst();
                break;

            case 5:
                deleteatend();
                break;

            // case 6:
            //     printf("Enter position=");
            //     scanf("%d", &index);
            //     deleteatposition(index);
            //     break;

            case 6:
                display();
                break;

            default:
                printf("Invalid option\n");
        }

        printf("Enter your choice =\n");
        scanf("%d", &choice);
    }

    return 0;
}

void display(){
    
	struct node *temp=head;
	printf("Forward Traversing :\n");
	if(head==NULL){
		printf("List is Empty \n");
		return;
	}
	do
	{
		printf(" %d", temp->data);
		temp=temp->next;
	}
	while(temp!=head);

	printf("\n");
}

void insertatfirst(int x){
struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=x; 
	new_node->next=NULL;
	new_node->prev=NULL;
	if(new_node==NULL){
		printf("Memory Unavailable:\n");
	}
	else if (head==NULL){
		head=new_node;
	}
	else{
	head->prev=new_node;
	new_node->next=head;
	head=new_node;
    }
}

void insertatend(int x){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
	struct node *temp=head;
	new_node->data=x; 
	new_node->next=NULL;
	new_node->prev=NULL;
	if(new_node==NULL){
		printf("Memory Unavailable:\n");
	}
	else if (head==NULL){
		head=new_node;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
    }

}

void insertatposition(int item, int index){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
	struct node *temp=head;
	struct node *temp2;
    int i;
	new_node->data=item; 
	new_node->next=NULL;
	new_node->prev=NULL;
	if(new_node==NULL)
	{	printf("Memory Unavailable:\n");	}
	else if (head==NULL)
	{	head=new_node;	}
	else
	{	for(i=0;i<index-1;i++)  
       		{  	temp2=temp;
			 temp = temp->next;  }  
       		new_node->next = temp;  
       		new_node -> prev = temp2;  
       		temp2->next = new_node;  
      		 temp->prev=new_node;  
       	}

}
void deleteatfirst(){
    struct node *temp = head;
    if (head == NULL) 
    {
        printf("List is Empty\n");
        return;
    }
    else if(temp->next == NULL){
        head = NULL;
    }
    else{
        temp = temp->next;
        head = temp;
        temp->prev = NULL;
    }
    free(temp);
}

void deleteatend(){ 
    struct node *temp = head;
    if (head == NULL) 
    {
        printf("List is Empty\n");
        return;   
    }
    else if (temp->next == NULL)
    {
        head = NULL;
    }
    else{
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }}

// void deleteatposition(int index){

// }