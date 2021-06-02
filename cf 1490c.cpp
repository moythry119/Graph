#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll f=0;
        for(ll i=1;i<=cbrt(x/2);i++)
        {
            ll k=pow(i,3);
         //   cout<<k<<endl;
            ll r=x-k;
            if(r<1)
            {
                break;
            }
       //     cout<<r<<endl;
            ll p=cbrt(r);
            if(r==p*p*p)
            {
                f=1;
                break;
            }

        }
        if(f)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
