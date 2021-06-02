#include <bits/stdc++.h>
using namespace std;
vector <int> adj[1000];
vector <int> cost[1000];
int visited[1000];
int dis[1000];
void BFS(int s)
{
    memset(dis,0,sizeof(dis));
    memset(visited,0,sizeof(visited));
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
   // parent[s]=-1;

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
               // parent[v]=u;
               dis[v]=dis[u]+cost[u][i];
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        cout<<"Case "<<i<<":"<<endl;

        for(int i=0;i<t-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);

        }
        int mx,d;
        for(int i=0;i<t-1;i++)
        {    mx=0,d=0;
            BFS(i);
            for(int i=0;i<t;i++)
            {
                if(mx<dis[i])
                {

                mx=dis[i];
                d=i;
                }
                cout<<dis[i]<<" ";
            }
            cout<<endl;
            BFS(d);
            mx=0;
            for(int i=0;i<t;i++)
            {
                if(mx<dis[i])
                {

                mx=dis[i];
               // d=i;
                }
            cout<<dis[i]<<" ";

            }
            cout<<endl;
            cout<<mx<<endl;
        }
         for(int i=0;i<n;i++)
        {
            adj[i].clear();
            cost[i].clear();

        }
    }
}
