#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000];
int vis[1000];
bool ok;
void dfs(int u)
{
int i,d=g[u].size();
vis[u]=1;
for(i=0;i<d;i++)
{

int v=g[u][i];
if(vis[v]==0)
{
dfs(v);
}
else if(vis[v]==1)
{
ok=1;
return;
}
vis[v]=2;
}
}
int main()
{
ok=0;
int i,x,y,n;
cin>>n;
for(i=1;i<=n;i++)
{
cin>>x>>y;
g[x].push_back(y);
//g[y].push_back(x);
}
dfs(1);
if(ok)
{
cout<<"YES"<<endl;

}
else
{
cout<<"NO"<<endl;
}
return 0;
}

