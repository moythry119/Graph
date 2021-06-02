#include<bits/stdc++.h>
using namespace std;

vector<int>adj[30000];
int visited[30000];
int dis[30000];
//vector<int>v;
vector<int>cost[30000];

void bfs(int s)
{
    memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(visited));

    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    dis[s]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                dis[v]=dis[u]+cost[u][i];
            }
        }
    }
}
int main()
{
    int t,tc;
    cin>>tc;
    for(t=0;t<tc;t++)
    {
        int mx,d;
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

        }
        mx=0;
        bfs(0);
        for(int i=0;i<n;i++)
        {
            if(mx<dis[i])
            {
                mx=dis[i];
                d=i;
            }
                        cout<<dis[i]<<" ";

        }
                cout<<endl;

        mx=0;
        bfs(d);
        for(int i=0;i<n;i++)
        {
            if(mx<dis[i])
            {
                mx=dis[i];
            }
                        cout<<dis[i]<<" ";

        }
        cout<<endl;
        cout<<"Case "<<t+1<<": "<<mx<<endl;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            cost[i].clear();

        }


    }
}
