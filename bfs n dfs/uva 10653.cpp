#include<bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
pair <int,int> pa;
    int r,c;
int mat[100][100];

int mark[100][100];
int d[1000][1000];
bool valid(int x, int y,int r, int c)
{
    if(x>=1 && x<=r && y>=1 && y<c && mat[x][y]!=1)
        return true;
    else
        return false;
}
void bfs(int x,int y)
{
  //  memset(vis,0,sizeof(vis));

    queue <pair<int,int> > q;
    q.push(make_pair(x,y));
    mark[x][y]=1;
    d[x][y]=0;
    //par[x][y]=-1;
    while(!q.empty())
    {
        pa=q.front();
        q.pop();
     //   n++;
        x=pa.first;
        y=pa.second;
        for(int i=0;i<3;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(valid(xx,yy,r,c) && mark[xx][yy]==0)
            {
               // n++;
                q.push(make_pair(xx,yy));
                mark[xx][yy]=1;
                d[xx][yy]=d[x][y]+1;
               // par[xx][yy]=par[x][y];
            }
        }

    }

    //n=0;
}


int main()
{

    memset(mat,0,sizeof(mat));

    memset(mark,0,sizeof(mark));
memset(d,0,sizeof(d));
//while(("%d %d",&r,&c)&&r&&c)
//{
cin>>r>>c;

int i,j;
int b,x,y,z,k;
cin>>b;
for(i=0;i<b;i++)
{
cin>>x>>y;
for(j=0;j<y;j++)
{
    cin>>z;
    mat[x][z]=1;
}
}

int s1,s2,e1,e2;
cin>>s1>>s2>>e1>>e2;
bfs(s1,s2);
cout<<d[e1][e2]<<endl;
}

