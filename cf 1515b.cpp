#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        ll p=log2(n);
        ll x=pow(2,p);


            if(x==n)
            {
                cout<<"YES"<<endl;
                continue;

            }
                        if(n%2==0)
            {

            ll k=n/2;
            ll sq=sqrt(k);
            if(sq*sq==k)
                        {
                cout<<"YES"<<endl;
                continue;

            }
    }
            if(n%4==0)
            {


            ll k4=n/4;
            ll sq4=sqrt(k4);
            if(sq4*sq4==k4)
                        {
                cout<<"YES"<<endl;
                continue;

            }
            }




            cout<<"NO"<<endl;



    }


}
