#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while (ptr !=NULL)
    {
        printf("Element=%d\n",ptr->data);
        ptr = ptr->next;
    }}
    
    struct node * atfirst(struct node *head,int value){
struct node *ptr=(struct node*)malloc(sizeof(struct node));
ptr->next=head;
ptr->data=value;
return ptr;
}
int main(){
    int value;
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
printf("Enter a element which you want to insert =");
scanf("%d",&value);
traversal(head);
printf("\nafter traverse\n");
head=atfirst(head,value);
traversal(head);
    return 0;
}