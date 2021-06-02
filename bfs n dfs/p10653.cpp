#include<bits/stdc++.h>
using namespace std;
int a[30][30];
int r,c;
int vis[1000][1000];
int lev[1000][1000];
pair <int,int> pa;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool valid(int x,int y)
{
    if(x>=1 && x<=r && y>=1 && y<=c && a[x][y]!=1)
        return true;
    else
        return false;
}
int bfs(int x,int y)
{
            memset(vis,0,sizeof(vis));
                  //      memset(lev,0,sizeof(lev));


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
    //n=0;
}
int main()
{


 //   cin>>r>>c;
     while(scanf("%d %d",&r,&c)==2)
{
    if(r==0 && c==0)
    {
        break;
    }
        memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,m,z;
        cin>>x>>m;
    //    while(m--)
    for(int j=0;j<m;j++)
        {
            cin>>z;
            a[x][z]=1;
        }
    }
    int s1,s2,e1,e2;
    cin>>s1>>s2;
    cin>>e1>>e2;
   // a[e1][e2]+=2;
 //   n=1;
    bfs(s1,s2);
   // int ans=lev[e1][e2];
    cout<<lev[e1][e2]<<endl;
}

}
