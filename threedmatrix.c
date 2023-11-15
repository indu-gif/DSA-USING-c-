#include <stdio.h>
int main(){
    int a[3][3][1];
    int i,j,k;
    printf("Enter Elements\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j= 0; j< 3; j++)
        {
            for ( k= 0; k < 1; k++)
            {
                scanf("\n%d",&a[i][j][k]);
            }
            
        }
        
    }
    printf("===========\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j= 0; j< 3; j++)
        {
            for ( k= 0; k < 1; k++)
            {
                printf("\n[%d] [%d] [%d]=%d",i,j,k,a[i][j][k]);
            }
            
        }
        
    }
    
}