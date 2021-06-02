#include<bits/stdc++.h>
using namespace std;

vector<int>adj[10000];
int visited[10000];

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
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
    }

    int cnt=0;
    for(int i=1; i<=node; i++)
    {
        if(visited[i]==0)
        {
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}

