#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll i,j;
ll maxnode=20001;
vector<vector<ll> >g(maxnode);
vector<ll> level(maxnode);
vector<ll> mark(maxnode);
vector<ll> parent(maxnode);
queue<ll> q;
void bfs(ll s, ll m)
{
 q.push(s);
 level[s]=0;
 parent[s]=-1;
 mark[s]=1;
 while(q.empty()==0)
{
 ll p=q.front();
 for(i=0;i<g[p].size();i++)
 {
 ll x=g[p][i]
 if(mark[x]==0)
 {
  q.push(x);
  mark[x]=1;
  parent[x]=p;
  level[x]=level[p]+1;
 }
 }
 q.pop();
}
cout<<level[m]<<endl;
}


int main()
{
ll n,m;
cin>>n>>m;
for(i=1;i<=10000;i++)
{
  g[i].push_back(i*2);
}
for(i=1;i<=10000;i++)
{
  g[i].push_back(i-1);
}
bfs(n,m);


}
