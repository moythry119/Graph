#include <bits/stdc++.h>
using namespace std;
vector <int> g[10000];
vector<int> ck(1000);
int n;

void dfs(int s)
{
int i;
if(ck[s]==1)
    return;
else
{
ck[s]=1;
cout<<s<<endl;
}
for(i=0;i<g[s].size();i++)
{
int u=g[s][i];

  dfs(u);
  //n++;




}


}



int main()
{
int n,i,s,e;
int u,v;

cin>>n>>s>>e;
for(i=0;i<e;i++)
{
cin>>u>>v;
g[u].push_back(v);
g[v].push_back(u);
}
n=0;
dfs(s);
//cout<<n<<endl;




}
