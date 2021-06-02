#include<bits/stdc++.h>
using namespace std;
vector<int> vec [30005];
vector<int>cost[30005];
int visited[30005];
int dis[30005];
int dis1[30005];
int n,b;

void bfs(int s)
{
    memset(visited,0,sizeof(visited));
memset(dis,0,sizeof(dis));
    queue<int>q;
    q.push(s);
    visited[s]=1;
    dis[s]=0;
    int mx=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u>mx)
        {
            b=u;
        }
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
                dis[v]=dis[u]+cost[u][i];
            }
        }

    }

}
void bfs1(int s)
{
    memset(visited,0,sizeof(visited));
memset(dis1,0,sizeof(dis1));
    queue<int>q;
    q.push(s);
    visited[s]=1;
    dis1[s]=0;
    int mx=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
                dis1[v]=dis1[u]+cost[u][i];
            }
        }

    }

}

int main()
{
int tc,t;
cin>>tc;
for(t=0;t<tc;t++)
{

    int a,b,c;
    cin>>n;

    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b>>c;
        vec[a].push_back(b);
        vec[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    bfs(0);
    int x=b;
    mx=0;
    bfs(x);
    x=b;
    bfs1(x);
    int fin=0;
    for(int i=0;i<n;i++)
    {
    fin=max(dis[i],dis1[i]);
    }
    cout<<"Case "<<t+1<<": "<<fin<<endl;
}
        for(int i=0;i<n;i++)
    {
        cost[i].clear();
        vec[i].clear();


    }
    mx=0;
    x=b=0;


  //  return 0;
}
