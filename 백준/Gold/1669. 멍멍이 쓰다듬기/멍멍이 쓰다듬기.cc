#include <stdio.h>

int main()
{
    long long int n,m,i=1,t;
    long long int sum=0;
    scanf("%lld %lld",&n,&m);
    while(sum+i<m-n)
    {
        sum=i*(i+1);
        i++;
    }
    if(sum>=m-n) printf("%d",(i-1)*2);
    else printf("%d",(i-1)*2+1);
}
