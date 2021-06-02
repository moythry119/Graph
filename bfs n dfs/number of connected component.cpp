#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool u[101];
ll x[101],y[101];
ll n;
void dfs(ll j)
{
    u[j]=1;
    for(ll i=0;i<n;i++)
    {
        if(((x[j]==x[i]) || (y[j]==y[i])) && (!u[i]))
        {
            dfs(i);
        }
    }
}
int main()
{
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(!u[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}
