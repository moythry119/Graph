#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000006];
int visited[1000006];
int level[1000006];
//pair <int,int> pa;

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
         //   pa = make_pair(v,i);
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
    int node;
    int a,b;
    cin>>node;
    for(int i=0; i<node-1; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
      //  adj[b].push_back(a);
    }

    BFS(0);
    float t=0;
    for(int i=0; i<node; i++)
    {
       // cout<<"level of node "<<i<<" is "<<level[i]<<endl;
       if(adj[i].size()==0)
       {
           t+=level[i];
       }
    }
    int k=adj[0].size();
   // cout<<t<<" "<<k<<endl;
    float ans=t/k;
    printf("%.15f\n",ans);
    return 0;
}


