#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 20001
vector<vector<ll> >g(max);
int arr[max];
bool visited[max];
ll ans=0;
ll n,m;
void dfs(ll src,ll ar)
{
	ll sum=0;
	visited[src]=true;
	if(ar>1)
   return;
	bool ok=false;
	for(ll i=0;i<g[src].size();i++)
	{
		ll x=g[src][i];
		if(visited[x]==false)
		{
		if(arr[x])
		{
			sum=ar+1;
			}
		else
		{
			sum=0;
			}
		dfs(x,sum);
		ok=true;	
		}
	}
	if(ok==false) ans++;
	
}
int main()
{
	ll i,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<n;i++)
	{
		
		g[p].push_back(q);
		g[q].push_back(p);

	}
	dfs(1,arr[1]);
	cout<<ans<<endl;
	return 0;
	
}
