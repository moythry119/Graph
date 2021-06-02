#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll a[n+1],b[n+1];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        ll p[x+1];
        for(ll i=0;i<x;i++)
        {
            cin>>p[i];
        }
        map<ll,ll>m;
        for(ll i=0;i<n-1;i++)
        {
            for(ll j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    m[j]=j+1;
                    m[j+1]=j;
                    swap(a[j],a[j+1]);
                }
            }
        }
      //  map<ll,ll> m:: iterator it;
      for(ll i=0;i<n;i++)
      {
          cout<<a[i]<<" ";
      }
      cout<<endl;
       for (auto i : m)
        cout << i.first << "   " << i.second
             << endl;


    }
}
