#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<30  //2^30
    vector<int>g[100005], cost[100005]; //this code can handle maximum 10000 nodes
    int par[100005];

struct node{
    int u;
    int cost;
    node(int _u, int _cost){
        u = _u;
        cost = _cost;
    }
    bool operator < ( const node& p ) const {      return cost > p.cost;   } //Operator overloading

};
int dijstkra(int n, int source){

    int distance[n+1];
    int dis2[n+1];
    for(int i=1;i<=n;i++) {
        distance[i] = infinity;
    }
        for(int i=1;i<=n;i++) {
        dis2[i] = 0;
    }

    priority_queue<node>q;
    q.push(node(source,0));
    distance[source] = 0;
    dis2[source]=0;
    par[source]=-1;

    while(!q.empty()){
        node top = q.top();
        q.pop();
        int u=top.u;
        if(u==n)
        {
            return dis2[u];
        }
        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];

            //Relaxation
            if(distance[u] + cost[u][i] < distance[v]){
                dis2[v]=distance[v];
                distance[v] = distance[u] + cost[u][i];
                q.push(node(v, distance[v]));
                par[v]=u;
            }
        }
    }
  //  for(int i=1;i<=n;i++){
    //    cout<<source<<" --> "<<n<<" = "<<distance[n]<<endl;
   // }
   return -1;
}
int main(){

    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int source=1;
    int d=dijstkra(numNodes,source);
     cout<<d<<endl;

    return 0;
}

