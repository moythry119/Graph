#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int parent[1000];
vector<int>v;

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    parent[s]=-1;

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
                parent[v]=u;
            }
        }
    }
}
int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    int d;
    cin>>d;
    int x=d;
    v.push_back(x);
    while(x!=-1)
    {
        x=parent[x];
        v.push_back(x);
    }
    v.erase(v.end()-1);
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
