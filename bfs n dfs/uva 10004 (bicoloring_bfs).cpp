#include<bits/stdc++.h>
using namespace std;
#define max 100000
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int e;
        cin>>e;
        vector<vector<int> >g(max);
        vector<int> color(max);
      //  memset(color,-1,sizeof(color));
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int f=0;
        queue<int> q;
        q.push(0);
        color[0]=1;
        while(q.empty()==0)
        {
            int p=q.front();
            q.pop();
            for(int j=0;j<g[p].size();j++)
            {
                int x=g[p][j];
                if(color[x]==0)
                {
                    if(color[p]==2)
                    {
                        color[x]=1;
                    }
                    else
                    {
                        color[x]=2;
                    }
                    q.push(x);
                }
                else
                {
                    if(color[x]==color[p])
                    {
                        f=1;
                        break;
                    }
                }
            }
            if(f==1)
                break;
        }
        if(f==1)
        {
            cout<<"NOT BICOLORABLE"<<endl;
        }
        else
        {
            cout<<"BICOLORABLE"<<endl;
        }
    }
}
