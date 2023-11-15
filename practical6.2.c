#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insertatfirst(int x);
void insertatend(int x);
void insertatposition(int item, int index);
void deleteatfirst();
void deleteatend();
void deleteatposition(int index);
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

            case 6:
                printf("Enter position=");
                scanf("%d", &index);
                deleteatposition(index);
                break;

            case 7:
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
	struct node *ptr=head;
	printf("Printing List:\n");
	if(head==NULL){
		printf("List is Empty \n");
		return;
	}
	do
	{
		printf(" %d", ptr->data);
		ptr=ptr->next;
	}
	while(ptr!=head);

	printf("\n");
}



void insertatend(int x){
    struct node *temp=head;
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x; 
	ptr->next=NULL;

	if(ptr==NULL){
		printf("Memory Unavailable:\n");
		return;
	}
	if (head==NULL){
		head=ptr;
		ptr->next=head;
		return;
	}
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->next=head;
}


void insertatfirst(int x){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = x;
    ptr->next = NULL;
    if (ptr == NULL) {
        printf("Memory Unavailable:\n");
        return;
    }
    if (head == NULL) {
        head = ptr;
        ptr->next = head;
        return;
    }
    while (temp->next != head) {
        temp = temp->next;
    }
    ptr->next = head;
    head = ptr;
    temp->next = head;
}

void insertatposition(int item, int index){
      struct node *newnode, *temp;
    int i;
    if (index == 1) {
        insertatfirst(item);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->next = NULL;
        temp = head;
        for (i = 0; i < index - 2; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteatfirst() {
    struct node *temp = head;
    struct node *temp2 = head;
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (temp->next == head) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != head) {
        temp = temp->next;
    }

    head = temp2->next;
    temp->next = head;
    printf("The deleted node is : %d\n", temp2->data);
    free(temp2);
}

void deleteatend() {
    struct node *temp = head;
    struct node *prev;
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (temp->next == head) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("The deleted node is : %d\n", temp->data);
    free(temp);
}

void deleteatposition(int index) {
    struct node *prev, *temp = head;
    int i;
    if (head == NULL) {
        printf(" List is Empty\n");
    } else if (index == 1) {
        deleteatfirst();
    } else {
        for (i = 0; i < index - 1; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("The deleted node is : %d\n", temp->data);
        free(temp);
    }
}
