#include <bits/stdc++.h>
using namespace std;
//vector< vector<int> > g(1000);
int vis[1000][1000];
int lev[1000][1000];
int par[1000][1000];

char a[30][30];
pair <int,int> pa;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c,n;
bool valid(int x, int y,int r, int c)
{
    if(x>=1 && x<=r && y>=1 && y<c && a[x][y]!='#')
        return true;
    else
        return false;
}
void bfs(int x,int y,int r,int c)
{
        memset(vis,0,sizeof(vis));

    queue <pair<int,int> > q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    lev[x][y]=0;
    par[x][y]=-1;
    while(!q.empty())
    {
        pa=q.front();
        q.pop();
        n++;
        x=pa.first;
        y=pa.second;
        for(int i=0;i<3;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(valid(xx,yy,r,c) && vis[xx][yy]==0)
            {
               // n++;
                q.push(make_pair(xx,yy));
                vis[xx][yy]=1;
                lev[xx][yy]=lev[x][y]+1;
                par[xx][yy]=par[x][y];
            }
        }

    }
             cout<<n<<endl;

    //n=0;
}
int main()
{
 int i,u,v;
 cin>>r>>c;
 for(i=1;i<=r;i++)
 {
     for(int j=1;j<=c;j++)
     {
        cin>>a[i][j];
        if(a[i][j]=='@')
        {
        u=i;
        v=j;
        }
     }
 }
 n=0;
 bfs(u,v,r,c);


}
