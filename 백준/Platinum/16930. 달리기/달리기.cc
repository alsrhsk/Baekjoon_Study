#include <stdio.h>
#include <vector>

using namespace std;

vector <pair<int,int>>ord;

int gym[1010][1010]={};
int con[1010][1010]={};
int mem[1010][1010]={};
int i,j,n,m,k,p=0;
int x1,x2,y11,y2,z;
int fx[4]={-1,0,1,0};
int fy[4]={0,-1,0,1};
/*u=1 d=3 l=2 r=4*/


void fu(int x, int y)
{
    if(mem[x2][y2]!=0)
    {
        printf("%d",mem[x2][y2]-1);
        p=-1;
        return;
    }
    for(i=1; i<=4; i++)
    {
        if(gym[x+fx[i-1]][y+fy[i-1]]==1 && (mem[x+fx[i-1]][y+fy[i-1]]>mem[x][y] || mem[x+fx[i-1]][y+fy[i-1]]==0))
        {
            z=0;
            if(i%2==1)
            {
                while((z<k && z+k>0) && gym[x+z+i-2][y]==1)
                {
                    z+=(i-2);
                    if(mem[x+z][y]>mem[x][y]+1 || mem[x+z][y]==0)
                    {
                        mem[x+z][y]=mem[x][y]+1;
                        if(z==k || z+k==0 || gym[x+z+i-2][y]==0) ord.push_back(make_pair(x+z,y));
                        else if(con[x+z][y]>2 || (con[x+z][y]==2 && gym[x+z+i-2][y]==0))
                                    ord.push_back(make_pair(x+z,y));
                    }
                }
            }
            else
            {
                while((z<k && z+k>0) && gym[x][y+z+i-3]==1)
                {
                    z+=(i-3);
                    if(mem[x][y+z]>mem[x][y]+1 || mem[x][y+z]==0)
                    {
                        mem[x][y+z]=mem[x][y]+1;
                        if(z==k || z+k==0 || gym[x][y+z+i-3]==0) ord.push_back(make_pair(x,y+z));
                        else if(con[x][y+z]>2 || (con[x][y+z]==2 && gym[x][y+z+i-3]==0))
                                    ord.push_back(make_pair(x,y+z));
                    }
                }
            }
        }
    }
}


int main()
{
    char q;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            scanf(" %c",&q);
            if(q=='.')
            {
                gym[i][j]=1;
                if(gym[i-1][j]==1)
                {
                    con[i-1][j]+=1;
                    con[i][j]+=1;
                }
                if(gym[i][j-1]==1)
                {
                    con[i][j-1]+=1;
                    con[i][j]+=1;
                }
            }
            else gym[i][j]=0;
        }
    scanf("%d %d %d %d",&x1,&y11,&x2,&y2);

    ord.push_back(make_pair(x1,y11));
    mem[x1][y11]=1;
    while(p<ord.size())
    {
        fu(ord[p].first,ord[p].second);
        if(p==-1) return 0;
        p++;
    }
    printf("-1");

}
