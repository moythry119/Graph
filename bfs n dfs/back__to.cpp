#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll tc;

void bfs(vector<vector<ll> >&g,vector<ll>&mark,ll src)
{
	queue<ll>q;
	vector<ll>color(10000);
	ll green,red;
	q.push(src);
	mark[src]=1;

	color[src]=1;
	green=1,red=0;

	while(!q.empty())
	{
		ll p=q.front();
		q.pop();

		for(ll i=0;i<g[p].size();i++)
		{
			ll x=g[p][i];

			if(mark[x]==0)
			{
				q.push(x);
				mark[x]=1;

				if(color[p]==1)
				{
					color[x]=0;
					red++;
				}
				else
				{
					color[x]=1;
					green++;
				}
			}
		}

	}

	ll mx=max(green,red);
	cout<<"Case "<<tc<<": "<<mx<<endl;
}

int main()
{
	ll n,x,y;
	
	ll t;
	cin>>t;
	for(tc=1;tc<=t;tc++)
	{
		
		cin>>n;
		vector<vector<ll> >g(100001);
   		vector<ll>mark(100001); 

		while(n--)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		bfs(g,mark,1);
		
	}
	


}
