#include <bits/stdc++.h>
using namespace std;
#define max 100
char mat[max][max];
int vis[max][max];
int cost[max][max];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int r,c,x,y,cnt=0;
queue<int>q;
void bfs(int s1,int s2)
{
    memset(vis,0,sizeof(vis));
    memset(cost,0,sizeof(cost));
    q.push(s1);
    q.push(s2);
    cost[s1][s2]=0;
    vis[s1][s2]=1;
    while(q.empty()==0)
    {
        int ux=q.front();
        q.pop();
        int uy=q.front();
        q.pop();
        cnt++;
        for(int k=0;k<4;k++)
        {
            int tx=ux+fx[k];
            int ty=uy+fy[k];
            if((tx>=0&&tx<r) && (ty>=0&&ty<c) && mat[tx][ty]!='#')
            {
                if(!vis[tx][ty])
                {
                    vis[tx][ty]=1;
                    cost[tx][ty]=cost[ux][uy]+1;
                }
            }
        }
    }
         //   cout<<"Case "<<tc+1<<": "<<cnt<<endl;
         cout<<cnt<<endl;
                    cnt=0;


}
int main()
{
    int tc,c;
    cin>>c;
    for(tc=0;tc<c;tc++)
    {
        int f=0;
        int i,j;
        cin>>r>>c;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='@')
                {
                   // x=i;
                    //y=j;
                    bfs(i,j);
                    f=1;
                    break;

                }
            }
            if(f==1)
                break;
        }
      //  bfs(x,y);
       // cout<<"Case "<<tc+1<<": "<<cnt<<endl;
      //  cnt=0;
    }
}
