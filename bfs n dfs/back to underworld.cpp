#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i,j;
ll maxnode=100001;
void bfs(ll caseno)
{
    ll n,e;
    cin>>e;
    n=e+1;
    vector<vector<ll> >g(maxnode);
    vector<ll> mark(maxnode);
    for(i=1;i<maxnode;i++)
        mark[i]=-1;
    for(i=1;i<=e;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        mark[x]=0;
        mark[y]=0;

    }
    ll tot=0;
    for(ll s=1;s<maxnode;s++)
    {

        if(mark[s]==0)
        {
            vector<ll>level(maxnode);
            for(i=1;i<=maxnode;i++)
            {

                level[i]=-1;
            }
            queue<ll>q;
            q.push(s);
            level[s]=0;
            mark[s]=1;
            while(q.empty()==0)
            {
                ll p=q.front();
                for(i=0;i<g[p].size();i++)
                {

                    ll x=g[p][i];
                    if(mark[x]==0)
                    {

                        q.push(x);
                        mark[x]=1;
                        level[x]=level[p]+1;
                    }
                }
                q.pop();
            }
            ll g1=0,g2=0;
            for(i=1;i<maxnode;i++)
            {

                if(level[i]>0 && level[i]%2==0)
                    g1++;
                else if(level[i]>0)
                {
                    g2++;
                }
            }
            tot+=max(g1,g2);
        }
    }
    cout<<"Case "<<caseno<<": "<<tot<<endl;
}
int main()
{

    ll t,caseno=0;
    cin>>t;
    while(t--)
    {
        bfs(++caseno);
    }
}
