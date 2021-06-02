#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod(string t,ll n)
{
    ll x=0;
    for(ll i=0;i<t.size();i++)
    {
        x=(x*10)+(t[i]-'0');
        x%=n;

    }
    return x;
}
string sol(ll n)
{
    queue<string>q;
    set<ll>s;
    string t="1";
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        ll r=mod(t,n);
        if(r==0)
        {
            return t;
        }
        else if(s.find(r)==s.end())
        {
            s.insert(r);
            q.push(t+"0");
            q.push(t+"1");
        }
    }

}
int main()
{
    ll k;
    cin>>k;
    while(k--)
    {
        ll n;
        cin>>n;
        cout<<sol(n)<<endl;
    }
}
