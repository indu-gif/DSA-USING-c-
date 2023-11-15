#include <stdio.h>
#include <stdlib.h>
struct singlelist
{
    int data ;
    struct singlelist *next;
};
int main(){
    struct singlelist *head;
    head= (struct singlelist *)malloc(sizeof(struct singlelist));
    head->data=569;
    head->next=second;
    
    struct singlelist *second;
    second=(struct singlelist *)malloc(sizeof(struct singlelist));
    second->data=45;
    second->next=third;

    struct singlelist *third;
    third=(struct singlelist *)malloc(sizeof( struct singlelist));
    third->data=78;
    third->next=NULL;

printf("%d",head->data);
    
}