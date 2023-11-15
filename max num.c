#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
int arr[n];
int i,temp;
for ( i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}
int maxmin=arr[0];

for ( i = 0; i < n; i++)
{
    if(arr[i]>maxmin){
    temp=arr[i];

    }
    
}
 printf("\n maximum = %d",temp);


    return 0;
}