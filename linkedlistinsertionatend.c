#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
struct node * next;
};

void traversal(struct node *ptr){
    while (ptr !=NULL)
    {
        printf("Element=%d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

struct node * atend(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while (p->next!=NULL)
    {
        p=p->next;;

    }
    p->next=ptr;
     ptr->next=NULL;
        return head;
    
}

int main(){
struct node*head;
struct node*second;
struct node*third;
struct node*fourth;

head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));
fourth=(struct node *)malloc(sizeof(struct node));

head->data=78;
head->next=second;

second->data=55;
second->next=third;

third->data=455;
third->next=fourth;

fourth->data=100;
fourth->next=NULL;

traversal(head);
printf("\nAfter insertion\n");
head=atend(head,56);
traversal(head);
    return 0;
}