#include<stdio.h>
int fab(int n){
    if(n<=1){
        return 1;
    }
        return fab(n-1)+fab(n-2);
}

int main(){
    int n,i;
    printf("Enter the term :");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("%d \n", fab(i));
    }
}