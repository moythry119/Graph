#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>fin;
vector < vector<int> > g;
vector<int> ck(1000);
int n;

void dfs(int s)
{
//   fill(ck,ck+n+1,0);


int i;
if(ck[s]==1)
    return;
else
{
ck[s]=1;
//cout<<s<<endl;
fin[s]=1;
}
for(i=0;i<g[s].size();i++)
{
int u=g[s][i];
if(ck[u]==0)
{
  dfs(u);
  //n++;

}


}


}
int main()
{
    //int n;
    while(1)
    {
       // scanf("%d",&n);
       cin>>n;
        if(n==0)
        {
            break;
        }
         g.clear();
        g.resize(n+1);
        while(1)
        {
                   int v;

           // scanf("%d",&v);
           cin>>v;
            if(v==0)
            {
                break;
            }
        while(1)
        {
                    int x;

            //scanf("%d",&x);
            cin>>x;
            if(x==0)
                break;
            g[v].push_back(x);
        }
    }
    int t;
   // scanf("%d",&t);
   cin>>t;
    while(t--)
    {
        int p;
        scanf("%d",&p);
        for(int i=1;i<=n;i++)
    {
    ck[i]=0;
    }
        dfs(p);

        for(int i=1;i<=n;i++)
        {
            if(ck[i]==0)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;

    }
    }
}
