#include <stdio.h>
int main(){
     int arr[3][3];
    int w,i,j;
    int base,lr=1,n=3,m=3,lc=1,address;
    base=(int)arr;
    w = sizeof(arr[0]);

    printf("\nRow Major Order \n");
    for ( i = 0; i < 3; i++)
    {
    for ( j= 0; j< 3; j++)
    {
        address= base + w*((i-lr)*n+(j-lc));
        printf("\nElement %d %d address is %u",i,j,(int *)address);
    }
    }
    printf("\nColumn Major Order \n\n\n");

    for ( i = 0; i < 3; i++)
    {
    for ( j= 0; j< 3; j++)
    {
        address= base + w*((j-lc)*m+(i-lr));
        printf("\nElement %d %d address is %u",i,j,(int *)address);
    }
    }
    return 0;
}