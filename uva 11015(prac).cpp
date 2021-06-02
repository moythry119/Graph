#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll mat[106][106];
        if(n==0 && m==0)
        {
            return 0;
        }
        map<string,ll>mp;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            mp[s]=i+1;
        }
        for(ll i=0;i<m;i++)
        {
            ll u,v,c;
            cin>>u>>v>>c;
            mat[u][v]=c;
        }
        for (int k = 0; k < 105; k++)
			for (int i = 0; i < 105; i++)
				for (int j = 0; j < 105; j++)
					mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
    }
}
