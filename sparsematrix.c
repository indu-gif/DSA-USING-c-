#include<stdio.h>
int main(){
    int m,n,k=0;
    int count=0;
    scanf("%d %d",&m,&n);
    int sm[m][n];
    int i,j;
    int count1=0;
    printf("enter matrix value");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j<n;j++)
        {
            scanf("%d",&sm[i][j]);
        }
        
    }
    
    for ( i = 0; i < m; i++)
    {
        for ( j= 0; j< n; j++)
        {

            if(sm[i][j]==0){

            count++;


            }
            else{
                count1++;
            }
        }
        
    }
    printf("Number of non zeros = %d\n",count1);
    int y[3][count1];
    if (count>count1)
{
    printf("matrix is sparse matrix\n");

     for ( i = 0; i < m; i++)
    {
        for ( j= 0; j< n; j++)
        {
            if(sm[i][j]!=0)
            {
                y[0][k] = i;
                y[1][k] = j;
                y[2][k] = sm[i][j];
                k++;
            }
        }

    }

}
else{
    printf("not sparse marix\n");
}

for ( i = 0; i < 3; i++)
    {
        for ( j= 0; j< count1; j++)
        {
            printf("%d ",y[i][j]);
        }
        printf("\n");
    }
    return 0;
}