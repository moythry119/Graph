#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    if(n%2)
    {
        n=(n/2)+1;
    }
    else
    {
        n/=2;
    }
        ll sev=n,fr=n;

    string t="";
    ll f=0;
    for(ll i=0;i<s.size();i++)
    {
            ll x=s[i]-'0';
       if(s[i]-'0'>=5)
        {
            if(f==0)
            {
              t+="7";
              sev--;
              f=1;
            }
            else
            {

              if(fr>0)
              {
                  t+="4";
                  fr--;
              }
            else if(sev>0)
              {
              t+="7";
              sev--;
              }
            }

        }
        else
        {
            if(fr>0)
            {
                t+="4";
                fr--;
            }
            else if(sev>0)
            {
                t+="7";
                sev--;
            }
        }
    }
    if(t.size()%2)
    {
        if(fr>0)
        {
            t+="4";
        }
        else
        {
            t+="7";
        }
    }
    cout<<t<<endl;
}
