#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<pair<long long int,long long int>> pq;
int main()
{
    int n,i,j,sum=0;
    int x,y,b=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&x,&y);
        pq.push(make_pair(-y,-x));
    }
    j=pq.size();
    for(i=0; i<j; i++)
    {
        if(-(pq.top().second)>=b)
        {
            b=-(pq.top().first);
            sum+=1;
        }
        pq.pop();
    }
    printf("%d",sum);
}
