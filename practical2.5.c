#include <stdio.h>
int main(){
    int a[3][3];
    int i,j;
    int count=0;
    int b;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    
    printf("\nEnter the element which you want to search = \n");
    scanf("%d",&b);
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
        if(a[i][j]==b){
            printf("\n Element find ");
        }
        count++;
        }
        
    }
    if(count==0){
        printf("Element not find");
    }
    
}