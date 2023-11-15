#include<stdio.h>
int linear(int arr[],int size,int element){
    int i;
for ( i = 0; i < size; i++)
{if(arr[i]==element){
    return i;
    }
    
}
return -1;
}
int main(){
    int arr[]={1,25,36,45,25};
    int size=sizeof(arr)/sizeof(int);
    int pass=linear(arr,size,45);
    int element=45;
    printf("%d element on %d index",element,pass);
    return 0;
}