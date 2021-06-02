#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<endl;
        int adj[7][7];
        int next[7][7];
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cin>>adj[i][j];
                if(adj[i][j]==-1)
                {
                    adj[i][j]=100000;
                }
                next[i][j]=j;
            }
        }
        int b[7];
        for(int i=1;i<6;i++)
        {
            cin>>b[i];
        }
        for(int k=1;k<=5;k++)
        {
            for(int i=1;i<=5;i++)
            {
                for(int j=1;j<=5;j++)
                {
                    if(adj[i][j]>(adj[i][k]+adj[k][j]+b[k]))
                    {

                    adj[i][j]=(adj[i][k]+adj[k][j]+b[k]);
                    next[i][j]=next[i][k];
                    }
                }
            }
        }
        int c,d,x,y;
          cin>>x>>y;
          c=x;
          d=y;
            vector<int>p;
            p.push_back(c);
            while(c!=d)
            {
                c=next[c][d];
                p.push_back(c);
            }
            for(int i=0;i<p.size();i++)
            {
                cout<<p[i]<<" ";
            }
            cout<<endl;
            cout<<adj[x][y]<<endl;



    }
}
