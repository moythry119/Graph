#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    vector <pair<ll,ll> >v;
    ll x=0;
    for(ll i=0;i<n;)
    {
        for(ll j=0;j<m;j++)
        {
          if(t[j]==s[i] && i<n)
          {
          //    cout<<i<<" "<<j<<endl;
              x++;
              i++;

          }
          else
          {
              if(x==m)
              {
                  v.push_back(make_pair((i-1)-(x-1),i-1));
              }
              x=0;
              i++;
              break;
          }
        }
    }
              if(x==m)
              {
                  ll i=n-1;
                  v.push_back(make_pair(i-(x-1),i));
              }

  /*  for(ll i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl<<endl; */
    while(q--)
    {
        ll x,y,ans=0;
        cin>>x>>y;
        x--;
        y--;
        for(ll i=0;i<v.size();i++)
        {
            if(x<=v[i].first && y>=v[i].second)
            {
                ans++;
            }
        }
        cout<<ans<<endl;

    }
}
