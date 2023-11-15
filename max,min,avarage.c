#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i ,max,min,sum=0;

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    max=min=arr[0];

for ( i = 0; i < n; i++)
{
    if(max<arr[i]){
        max=arr[i];
    }
    if (min>arr[i])

    {
        min=arr[i];    }
    
}
printf("maximum=%d",max);
printf("\nminimum=%d",min);

for ( i = 0; i < n; i++)
{
    sum=sum+arr[i];
}
printf("\nAvarage=%d",sum/n);
}