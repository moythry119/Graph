#include <bits/stdc++.h>
using namespace std;
int vis[1000][1000];
int lev[1000][1000];
int par[1000][1000];

char a[30][30];
pair <int,int> pa;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c,n,mx,x1,x2,nm;
bool valid(int x, int y,int r, int c)
{
    if(x>=1 && x<=r && y>=1 && y<c && a[x][y]!='#')
        return true;
    else
        return false;
}
void dfs(int x,int y)
{
int i;
vis[x][y]=nm;
n++;
if(n>mx){
    x1=x;
    x2=y;
    mx=n;
}
for(i=0;i<=3;i++)
{
int xx=x+dx[i];
int yy=y+dy[i];
if(valid(xx,yy,r,c) && vis[xx][yy]==0)
{
dfs(xx,yy);
}
}
n--;
vis[x][y]=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));

       nm=0;
        int i,j;
        cin>>c>>r;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
            cin>>a[i][j];
            }
        }
        nm=1;
        n=0;
        mx=0;
                for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
            if(a[i][j]=='.')
            {
              dfs(i,j);
              i=r;
              break;
            }
            }
        }

        nm=2;
        n=0,mx=0;
        dfs(x1,x2);
        cout<<"Maximum rope length is "<<mx-1<<"."<<endl;

    }
}
