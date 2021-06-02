#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int level[1000];
pair <int,int> pa;

void BFS(int s)
{
    memset(level,0,sizeof(level));
        memset(visited,0,sizeof (visited));

    queue<int>Q;
    Q.push(s);
    level[s]=0;
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            pa = make_pair(v,i);
            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                Q.push(v);
                visited[v]=1;
            }
        }

    }
}
int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    for(int i=1; i<=node; i++)
    {
        cout<<"level of node "<<i<<" is "<<level[i]<<endl;
    }
    return 0;
}

