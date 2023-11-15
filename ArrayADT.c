#include<stdio.h>
#include<stdlib.h>
struct ArrayADT
{
    int total_size;
    int used_size;
int *ptr;
};
void creatarray(struct ArrayADT* a,int tsize,int usize)
{
    (*a).total_size=tsize;
        (*a).used_size=usize;
(*a).ptr=(int*)malloc(tsize*sizeof(int));
}
int main(){
struct ArrayADT marks;
creatarray(&marks,100,20);
    return 0;
}