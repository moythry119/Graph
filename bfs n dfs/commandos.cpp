#include <bits/stdc++.h>
using namespace std;
vector <int> g[1000];
int n,r;

int bfs(int s,int d)
{
                vector<int>v[2];

    int tot=0;
    for(int j=1;j<=2;j++)
    {

            vector <int> level(1000);
vector <int> mark(1000);

        int src;
        if(j==1)
            src=s;
        else
            src=d;
        queue<int>q;
        q.push(src);
        level[src]=0;
        mark[src]=1;
        while(q.empty()==0)
        {
            int p=q.front();
            for(int i=0;i<g[p].size();i++)
            {
                int x=g[p][i];
                if(mark[x]==0)
                {
                    q.push(x);
                    mark[x]=1;
                    level[x]=level[p]+1;
                }
            }
            q.pop();
        }
        v[j-1]=level;
    }
    vector<int>temp(v[0].size());
    for(int i=0;i<v[0].size();i++)
    {
        temp[i]=v[0][i]+v[1][i];
    }
    sort(temp.begin(),temp.end());
     tot=temp.back();
   //  cout<<tot<<endl;
    return tot;

}
int main()
{
    int t,tc;
    cin>>tc;
    for(t=0;t<tc;t++)
    {

        cin>>n>>r;
        for(int i = 0; i < n; i++)
			g[i].clear();

        for(int i=0;i<r;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int s,d;
        cin>>s>>d;
     // bfs(s,d);
        cout<<"Case "<<t+1<<": "<<bfs(s,d)<<endl;

    }


}
