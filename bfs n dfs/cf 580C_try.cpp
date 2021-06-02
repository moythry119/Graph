#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 10000001
int iscat[max];
bool visited[max];
vector<vector<int> >g(max);
int n,m,ans=0;
void dfs(int s,int cats)
{
 int sum=0;
 visited[s]=true;
 if(cats>m)
 return;
 bool ok=false;
 for(int j=0;j<g[s].size();j++)
 {
 int x=g[s][j];
 if(!visited[x])
 {
 if(iscat[x])
 {
     sum=cats+1;
 }
 else
 {
     sum=0;
 }
 dfs(x,sum);
 ok=true;
 }
 }
 if(!ok)
 ans++;
}
int main()
{
int x,y;
cin>>n>>m;
int i;
for(i=1;i<=n;i++)
{
cin>>iscat[i];
}
for(i=1;i<n;i++)
{
 cin>>x>>y;
 g[x].push_back(y);
  g[y].push_back(x);

}
dfs(1,iscat[1]);
cout<<ans<<endl;
}
