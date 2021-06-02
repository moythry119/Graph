#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,y;
ll p[100];
ll fx(ll x)
{
    if(p[x]!=x)
    {
        p[x]=fx(p[x]);

    }
    return p[x];
}
int main()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        p[i]=i;
    }
    while(m--)
    {
        cin>>x>>y;
        p[fx(x)]=fx(y);
    }
    ll ans=(1LL<<n);
    for(ll i=1;i<=n;i++)
    {
        if(fx(i)==i)
        {
            ans/=2;
        }
    }
    cout<<ans<<endl;
}
