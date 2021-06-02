#include<bits/stdc++.h>
using namespace std;
const int inf = 20 * 20 * 20;
#define ll long long
#define mx 1000
vector<vector<ll> >g(mx);
int vis[mx][mx];
int dis[mx][mx];
char ar[mx][mx];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int m, n;
//cin>>m>>n;
queue<pair<int,int> >q;
int bfs(int s1,int s2,int r,int c)
{
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    int k,i,j;
    q.push(make_pair(s1,s2));
    vis[s1][s2]=1;
    dis[s1][s2]=0;
    while(q.empty()==0)
    {
        int ux=q.front().first;
        int uy=q.front().second;
        q.pop();
        if(g[ux][uy]=='h')
        {
            return dis[ux][uy];
        }
        for(k=0;k<4;k++)
        {
            int tx=ux+fx[k];
            int ty=uy+fy[k];
            if((tx>=0&&tx<r) && (ty>=0&&ty<c) && ar[tx][ty]!='#' && ar[tx][ty]!='m' && dis[tx][ty]==inf )
            {
                vis[tx][ty]=1;
                dis[tx][ty]=dis[ux][uy]+1;
                q.push(make_pair(tx,ty));


            }
        }
    }


}
int main()
{
     int i,j,x,y,u,v,d,e;
     cin>>m>>n;
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             cin>>ar[i][j];
             if(ar[i][j]=='a')
             {
                 x=i;
                 y=j;
             }
             if(ar[i][j]=='b')
             {
                 u=i;
                 v=j;
             }
             if(ar[i][j]=='c')
             {
                 d=i;
                 e=j;
             }

         }
     }
         int time=0;
         time=max(time,bfs(x,y,m,n));
         time=max(time,bfs(u,v,m,n));
         time=max(time,bfs(d,e,m,n));

     }

