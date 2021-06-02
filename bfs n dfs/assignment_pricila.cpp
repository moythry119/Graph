#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int parent[1000];
vector<int>v;

void BFS(int s)
{
   memset(parent,-1,sizeof parent);
    memset(visited,0,sizeof visited);
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
    cout<<"***Creating The Given Graph <Vertex 0 - 8>***"<<endl;
    int node=9;
        adj[0].push_back(1);
        adj[0].push_back(3);
        adj[0].push_back(4);
        adj[1].push_back(2);
        adj[1].push_back(4);
        adj[2].push_back(5);
        adj[3].push_back(4);
        adj[3].push_back(6);
        adj[4].push_back(5);
        adj[4].push_back(7);
        adj[6].push_back(4);
        adj[6].push_back(7);
        adj[7].push_back(5);
        adj[7].push_back(8);


    cout<<"Option 1: Adjacency nodes of a node."<<endl;
    cout<<"Option 2: Shortest path from a node."<<endl;
    cout<<"Enter an option: ";
    int op;
    cin>>op;

    if(op==1)
    {
        for(int i=0;i<node;i++)
        {
            int s=i;
            cout<<i<<": ";

            for(int l=0;l<adj[s].size();l++)
            {
                cout<<adj[s][l]<<" ";
            }
            cout<<endl;
        }
    }
    else if(op==2)
    {
        for(int i=0;i<node;i++)
        {
            int s=i;
            BFS(s);
            for(int j=0;j<node;j++)
            {
                int x=j;
                if(i==j)
                {
                    continue;
                }
                v.push_back(x);
                while(x!=-1)
                {
                    x=parent[x];
                    v.push_back(x);
                }

                v.erase(v.end()-1);
                reverse(v.begin(),v.end());
                cout<<"Shortest path from "<<i<<" to "<<j<<": ";
                if(v.size()<=1)
                {
                    cout<<"No path "<<endl;
                }

                else
                {
                for(int k=0; k<v.size(); k++)
                {
                    cout<<v[k]<<" ";
                }
                cout<<endl;
                }
                v.clear();
            }
         }
    }
    else
      return 0;

}
