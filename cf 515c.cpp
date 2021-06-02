#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,string>m;
    m['2']="2";
    m['3']="3";
    m['4']="322";
    m['5']="5";
    m['6']="53";
    m['7']="7";
    m['8']="7222";
    m['9']="7332";
    string t="";
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='1' || s[i]=='0')
        {
            continue;
        }
        t+=m[s[i]];

    }
    sort(t.begin(),t.end());
    for(ll i=t.size()-1;i>=0;i--)
    {
        cout<<t[i];
    }
    cout<<endl;

}
