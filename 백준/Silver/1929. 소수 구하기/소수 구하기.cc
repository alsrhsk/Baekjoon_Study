#include <stdio.h>

int d[1000010]={};
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=2; i<=m; i++)
    {
        if(d[i]==0)
        {
            if(i>=n)
                printf("%d\n",i);
            for(j=2; j<=m/i; j++)
            {
                d[i*j]=1;
            }
        }
    }
}
