#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
struct node * next;
};
int main(){
struct node*head;
struct node*second;
struct node*third;
head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));
head->data=5;
head->next=second;

second->data=55;
second->next=third;

third->data=5;
third->next=NULL;

    return 0;
}