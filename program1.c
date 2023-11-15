#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){

        scanf("%d",&arr[i]);

    }
    printf("=======");
    for(i=0;i<n;i++){

        printf("\n%d\t",arr[i]);
    }
    return 0;
}