#include <bits/stdc++.h>
using namespace std;
char a[30][30];
int r,c;
int vis[1000][1000];
int lev[1000][1000];
pair <int,int> pa;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool valid(int x,int y)
{
    if(x>=1 && x<=r && y>=1 && y<=c && a[x][y]!='#' && a[x][y]!='m')
        return true;
    else
        return false;
}
int bfs(int x,int y)
{
            memset(vis,0,sizeof(vis));

    queue <pair<int,int> > q;
    vis[x][y]=1;
    lev[x][y]=0;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pa=q.front();
        x=pa.first;
        y=pa.second;
        q.pop();
        if(a[x][y]=='h')
        {
            return lev[x][y];
        }

        for(int i=0;i<4;i++)
        {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(valid(xx,yy) && vis[xx][yy]==0)
        {
            vis[xx][yy]=1;
            lev[xx][yy]=lev[x][y]+1;
            q.push(make_pair(xx,yy));
        }


        }
    }

}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        cin>>r>>c;
        int a1,a2,b1,b2,c1,c2;
        for(int j=1;j<=r;j++)
        {
            for(int k=1;k<=c;k++)
            {
                cin>>a[j][k];
                if(a[j][k]=='a')
                {
                    a1=j;
                    a2=k;
                }
                if(a[j][k]=='b')
                {
                    b1=j;
                    b2=k;
                }
                if(a[j][k]=='c')
                {
                    c1=j;
                    c2=k;
                }
            }
        }
        int time=0;
         time=max(time,bfs(a1,a2));
         time=max(time,bfs(b1,b2));
         time=max(time,bfs(c1,c2));
         cout<<"Case "<<i+1<<": "<<time<<endl;
    }

}
