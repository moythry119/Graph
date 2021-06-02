#include <bits/stdc++.h>
using namespace std;
char a[30][30];
int r,c,n=1;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[1000][1000];
bool valid(int x, int y,int r, int c)
{
    if(x>=1 && x<=r && y>=1 && y<c && a[x][y]!='#')
        return true;
    else
        return false;
}
void dfs(int x,int y)
{
memset(vis,0,sizeof(vis));
int i;
vis[x][y]=1;
for(i=0;i<=3;i++)
{
int xx=x+dx[i];
int yy=y+dy[i];
if(valid(xx,yy,r,c) && vis[xx][yy]==0)
{
dfs(xx,yy);
 n++;
}
}

//n=0;
}
int main()
{
 int n,i,u,v;
 cin>>r>>c;

 //cin>>n;
 memset(vis,0,sizeof(vis));
 for(i=1;i<=r;i++)
 {
     for(int j=1;j<=c;j++)
     {
        cin>>a[i][j];
     }
 }
 //n=1;
 dfs(1,1);
  cout<<n<<endl;


}
