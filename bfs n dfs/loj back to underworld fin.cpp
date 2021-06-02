
#include <bits/stdc++.h>
using namespace std;
vector <int> g[1000];
int clr[1000];
vector <int> level;
int bfs(int src)
{
    int mx=0;
    int v=0,l=0;
  queue<int> q;
    q.push(src);
    clr[src]=1;
     v++;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<g[p].size();i++)
        {
            int x=g[p][i];
            if(clr[x]==0)
            {
                if(clr[p]==2)
                {
                    clr[x]=1;
                    v++;
                }
                else
                    clr[x]=2;
                    l++;
            }
        }
   }
   cout<<l<<" "<<v<<endl;
     mx+=max(l,v);
    return mx;
    }


int main()
{
    int t,tc;
    cin>>tc;
    for(t=0;t<tc;t++)
    {
        int m=0;
        memset(clr,0,sizeof(clr));
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    cout<<m<<endl;



}
}
