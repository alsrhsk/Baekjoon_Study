#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

queue <pair<int,int>>ice;
queue <pair<int,int>>swan[2];
int d[1502][1502]={};
int nu[5]={1,0,-1,0,1};
int n,m,i,j,q,c;

void me(int x, int y, int b)
{
    if(x<1 || x>n || y<1 || y>m) return;
    c=0;
    for(int z=0; z<=3; z++)
    {
        if(d[x+nu[z]][y+nu[z+1]]!=d[x][y])
        {
            if(d[x+nu[z]][y+nu[z+1]]==1)
            {
                d[x+nu[z]][y+nu[z+1]]=d[x][y];
                swan[b].push(make_pair(x+nu[z],y+nu[z+1]));
            }
            else if(d[x+nu[z]][y+nu[z+1]]>=2)
            {
                i=-2;
                return;
            }
            else if(c==0)
            {
                c=-1;
                swan[!b].push(make_pair(x,y));
            }
        }
    }
}

void br(int x, int y)
{
    if(x<1 || x>n || y<1 || y>m) return;
    d[x][y]=1;
    for(j=0; j<=3; j++)
    {
        if(d[x+nu[j]][y+nu[j+1]]==0)
        {
            ice.push(make_pair(x+nu[j],y+nu[j+1]));
            d[x+nu[j]][y+nu[j+1]]=-1;
        }
    }
}

int main()
{
    char a;
    int k=2;

    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            scanf(" %c",&a);
            if(a=='X')
            {
                d[i][j]=0;
                if(d[i-1][j]>0 || d[i][j-1]>0)
                {
                    ice.push(make_pair(i,j));
                    d[i][j]=-1;
                }
            }
            else
            {
                if(d[i-1][j]==0)
                {
                       d[i-1][j]=-1;
                       ice.push(make_pair(i-1,j));
                }
                if(d[i][j-1]==0)
                {
                       d[i][j-1]=-1;
                       ice.push(make_pair(i,j-1));
                }
                if(a=='.')
                {
                    d[i][j]=1;
                }
                if(a=='L')
                {
                    d[i][j]=k;
                    k+=1;
                    swan[0].push(make_pair(i,j));
                }
            }
        }

    k=1;
    for(q=0; ; q++)
    {
        k= !k;
        while(!swan[k].empty())
        {
            me(swan[k].front().first, swan[k].front().second,k);
            swan[k].pop();
            if(i==-2)
            {
                printf("%d",q);
                return 0;
            }
        }
        c=ice.size();
        for(i=0; i<c; i++)
        {
            br(ice.front().first, ice.front().second);
            ice.pop();
        }
    }
}
