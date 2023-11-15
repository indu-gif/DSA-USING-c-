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
struct node *after(struct node *head,struct node *pnode, int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
ptr->next=pnode->next;
pnode->next=ptr;
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
head =after(head,third,89);
traversal(head);
    return 0;
}