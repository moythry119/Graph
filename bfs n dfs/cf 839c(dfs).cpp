#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

double ans= 0.0;
vector<int> adj[MAXN];

void dfs (int s, int parent, double prob, int d) {
    int below = 0;
    for (int i: adj[s]) {
        if (i != parent) {
            below++;
        }
    }
    for (int i: adj[s]) {
        if (i != parent) {
            dfs (i, s, prob/below, d+1);
        }
    }
    if (below == 0) {
        ans+= prob*d;
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
        adj[b].push_back(a);
    }

    dfs(0,0,1.0,0);

    printf("%.15f\n",ans);
    return 0;
}



