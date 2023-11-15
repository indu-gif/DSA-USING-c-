#include<stdio.h>
int main(){
    int arr[3][3];
    int w,i;
    int base,lr=1,n=3,address;
    base=(int)arr;
    w = sizeof(arr[0]);
    for ( i = 0; i < 3; i++)
    {
        address= base + w * (i-lr);
        printf("\nElement %d address is %u",i,(int *)address);
    }
    
}