#include <stdio.h>
#include <vector>

using namespace std;

vector <int> pri;
int mem[1000003]={};

int main()
{
    long long int n,m,i,j,k,sum=0;
    int chk;
    scanf("%lld %lld",&n,&m);
    if(m>=4)
    {
        pri.push_back(2);
        for(k=4*(n/(4)); k<=m; k+=4)
        {
            if(k>=n)
                if(mem[k-n]==0)
                {
                    mem[k-n]=1;
                    sum+=1;
                }
        }
    }
    else
    {
        printf("%lld",m-n+1);
        return 0;
    }
    for(i=3; i*i<=m; i+=2)
    {
        chk=0;
        for(j=0; (j<pri.size() && pri[j]<=i*i); j++)
        {
            if(i%pri[j]==0) chk=1;
            break;
        }
        if(chk==0)
        {
            pri.push_back(i);
            for(k=i*i*(n/(i*i)); k<=m; k+=i*i)
            {
                if(k>=n)
                    if(mem[k-n]==0)
                    {
                        mem[k-n]=1;
                        sum+=1;
                    }
            }
        }
    }
    printf("%lld",(m-n+1)-sum);
}
