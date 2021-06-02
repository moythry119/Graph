#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m,cs,x,y;
    char name[105][105];
    while(scanf("%d",&n)==1)
    {
        map<string,int> R;
        vector<int>g[105];
        int indeg[105]={};
        for(int i=0;i<n;i++)
        {
      //  string s;
       // cin>>name[i];
       scanf(" %s",name[i]);
        R[name[i]] = i;

       // r[name[i]]=i;
        }
        scanf("%d",&m);
        while(m--)
        {
            string a,b;
            cin>>a;
            x=R[a];
            cin>>b;
            y=R[b];
            g[x].push_back(y);
            indeg[y]++;
        }
        priority_queue<int, vector<int>, greater<int> >q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
            printf("Case #%d: Dilbert should drink beverages in this order:", ++cs);
            while(!q.empty())
            {
                int v=q.top();
                q.pop();
                vector<int>::iterator it ;
                for(it=g[v].begin();it!=g[v].end();it++)
                {
                    indeg[*it]--;
                    if(indeg[*it]==0)
                    {
                        q.push(*it);
                    }
                }
                printf(" %s",name[v]);
            }
            puts(".\n");

    }
}
