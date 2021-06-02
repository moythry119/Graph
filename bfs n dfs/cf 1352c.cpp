#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll x=k/(n-1);
        if((x+k)%n==0)
        {
            cout<<x+k-1<<endl;
        }
        else
        {
            cout<<x+k<<endl;
        }

    }
}
