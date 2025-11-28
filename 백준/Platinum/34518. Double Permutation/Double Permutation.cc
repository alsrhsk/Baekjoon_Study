#include <stdio.h>

int d[3][5010]={};
int main()
{
    int n,k=0;
    int i,j;
    scanf("%d",&n);
    if(n%4==0 || n%4==1)
    {
        while(n-2*k>n%4)
        {
            d[1][1+k]=n-2*k;
            d[2][n-k]=n-2*k;
            d[2][1+k]=n-2*k-1;
            d[1][n-k-1]=n-2*k-1;
            d[1][1+k+1]=n-2*k-2;
            d[1][n-k]=n-2*k-2;
            d[2][n-k-1]=n-2*k-3;
            d[2][1+k+1]=n-2*k-3;
            k+=2;
        }
        if(n%4==1)
        {
            d[1][n/2+1]=1;
            d[2][n/2+1]=1;
        }
        for(i=1; i<=2; i++)
        {
            for(j=1; j<=n; j++)
            {
                printf("%d ",d[i][j]);
            }
            printf("\n");
        }
    }
    else printf("-1");
}
