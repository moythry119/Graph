#include <bits/stdc++.h>
using namespace std;
//vector< vector<int> > g(1000);
int vis[1000][1000];
int lev[1000][1000];
int par[1000][1000];

char a[30][30];
pair <int,int> pa;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={-1,1,-1,1,2,-2,-2,2};
int r=8,c=8,n;
bool valid(int x, int y,int r, int c)
{
    if(x>=1 && x<=r && y>=1 && y<=c)
        return true;
    else
        return false;
}
void bfs(int x,int y)
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
        for(int i=0;i<8;i++)
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

    //n=0;
}
int main()
{
 int i,j;
string s,e;
cin>>s>>e;
i=s[1]-'0';
j=s[0]-'a';
 n=1;
  bfs(i+1,j+1);
  int m=e[1]-'0';
  int n=e[0]-'a';
int  ans=lev[m+1][n+1];

cout<<ans<<endl;



}

