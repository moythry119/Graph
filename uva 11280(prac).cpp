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
        int n;
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            mp.insert(make_pair(s,i));
        }
        int m;
        cin>>m;
       // int cost[n+1][m+1];
        vector< vector<int> > adj(n+1),cost(n+1);
        for(int k=1;k<m;k++)
        {
            string s,t;
            int c;
            cin>>s>>t>>c;
            int i=mp[s];
            int j=mp[t];
            adj[i].push_back(j);
            adj[j].push_back(i);
            cost[i].push_back(j);
            cost[j].push_back(i);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int x;
            cin>>x;

                int dis[n+1];
                for(int i=0;i<n;i++)
                {
                    dis[i]=INT_MAX;
                }
                dis[0]=0;
                for(int k=0;k<x;k++)
                {
                    for(int u=0;u<n;u++)
                    {
                        for(int j=0;j<adj[u].size();j++)
                        {
                            int v=adj[u][j];
                            if(dis[u]+cost[u][j]<dis[v])
                            {
                                dis[v]=dis[u]+cost[u][j];
                            }
                        }
                        }
                    }
                    int ans=0;
                    for(int i=0;i<n;i++)
                    {
                        cout<<dis[i]<<endl;
                      ans+=dis[i];
                    }
                    cout<<ans<<endl;
                }



                    }
        }


