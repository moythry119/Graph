#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define infinity 1<<28

void bellman(int n, vector<int>g[], vector<int>cost[], int source){
    int distance[n+1];
    for(int i=1;i<=n;i++){
        distance[i] = infinity;
    }
    distance[source] = 0;
    bool neg_cycle = false;

    for(int k=1;k<=n;k++){
        bool updated = false;
        for(int u=1;u<=n;u++){
            for(int i=0;i<(int)g[u].size();i++){
                int v = g[u][i];
                //Relaxation
                if(distance[u] + cost[u][i] < distance[v]){
                    updated = true;
                    distance[v] = distance[u] + cost[u][i];
                }
            }
        }

        if(k==n and updated==true){ //update in the n^th iteration
            neg_cycle = true;
        }
    }
    if(neg_cycle)
    {
        cout<<"possible"<<endl;
    }
    else
    {
        cout<<"Not possible"<<endl;
    }
}
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[1000],cost[1000];
        for(int i=0;i<n;i++)
        {
            int x,y,t;
            cin>>x>>y>>t;
           // x--;
          //  y--;
            adj[x].push_back(y);
            cost[x].push_back(t);

        }
        int source=0;
        bellman(n, adj, cost, source);

    }
}
