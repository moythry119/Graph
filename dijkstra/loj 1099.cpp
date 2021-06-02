#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <utility>


using namespace std;
#define SIZE 5005
#define clr(a) memset(a,0,sizeof a);
#define reset(a) memset(a,-1,sizeof a);

struct node{
    int n,cost;
    node(){
    }
    node(int n,int cost)
    {
        this->n=n;
        this->cost=cost;
    }
    bool operator <(const node &nd) const{
        return cost>nd.cost;
    }


};
vector<node> adj[SIZE];
bool visted[SIZE];
int weight[SIZE];
int weight2[SIZE];
int minWeight[SIZE];
bool bck[SIZE];
int n,r;

int dijkstra(int start,int fin)
{
    priority_queue<node>q;
    q.push(node(start,0));
    clr(visted);
    reset(weight);
    reset(weight2);
    clr(bck);
    weight[start]=0;
    node nd,tmp;
    for(int i=0;i<n;i++)
    {
        minWeight[i]=INT_MAX;
        for(int j=0;j<adj[i].size();j++)
        {
            minWeight[i]=min(minWeight[i],2*adj[i][j].cost);
        }
    }
    while(!q.empty())
    {
        nd=q.top();
        q.pop();
        if(visted[nd.n])
        {
            if(weight[nd.n]<nd.cost && (weight2[nd.n]==-1 || weight2[nd.n]>=nd.cost))
            {
                weight2[nd.n]=nd.cost;
            }
                else
                    continue;

        }
        else
            visted[nd.n]=true;
    }
    for(int i=0;i<adj[nd.n].size();i++)
    {
        tmp=adj[nd.n][i];
        if(weight[tmp.n]==-1 || weight[tmp.n]>nd.cost+tmp.cost)
        {
            q.push(node(tmp.n,nd.cost+tmp.cost));
            weight2[tmp.n]=weight[tmp.n];
            weight[tmp.n]=nd.cost+tmp.cost;

        }
        else if(weight2[tmp.n]==-1 || weight2[tmp.n]>nd.cost+tmp.cost )
        {
            if(weight[tmp.n]!=tmp.cost+nd.cost)
            {
                q.push(node(tmp.n,nd.cost+tmp.cost));
            }
        }
        if(!bck[nd.n])
        {
            q.push(node(nd.n,weight[nd.n]+minWeight[nd.n]));
            bck[nd.n]=true;
        }
    }

    return weight2[fin];
}

int main()
{
    int t;
    scanf("%d",&t);
     for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<r;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(node(v,w));
            adj[v].push_back(node(u,w));
        }
        int result = dijkstra(1,n);
        printf("Case %d: %d\n",i+1, result);

    }
}
