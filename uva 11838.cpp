#include<bits/stdc++.h>

using namespace std;

vector<int>adj[10000],adj2[10000];
bool visited[10000]={false},visited2[10000]={false};
int dis[10000]={0};
int fin[10000]={0},tim=0;
stack<int>st;

void dfs(int s)
{
    visited[s]=true;
    tim++;
    dis[s]=tim;
    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(!visited[x]){
            visited[x];
            dfs(x);
        }
    }
    tim++;
    fin[s]=tim;
    st.push(s);
}
void scc_dfs(int s)
{
    visited2[s]=true;
    for(int i=0;i<adj2[s].size();i++){
        int x=adj2[s][i];
        if(!visited2[x]){
            visited2[x]=true;
            scc_dfs(x);
        }
    }
}


int main()
{
    int t,n,m,i,j,cnt,u,v,w,p;
    while(1)
    {
        cin>>n>>m;
        if(n==0&&m==0) return 0;
        memset(visited,0,sizeof(visited));
        memset(visited2,0,sizeof(visited2));
        memset(dis,0,sizeof(dis));
        memset(fin,0,sizeof(fin));
        tim=0,cnt=0;
        for(i=0;i<=n;i++){
            adj[i].clear();
            adj2[i].clear();
        }
        for(i=0;i<m;i++){
            cin>>v>>w>>p;
            if(p==1){
               adj[v].push_back(w);
               adj2[w].push_back(v);
            }

            else if(p==2){
               adj[v].push_back(w);
               adj[w].push_back(v);
               adj2[v].push_back(w);
               adj2[w].push_back(v);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
               dfs(i);
        }
        while(!st.empty())
        {
            int x=st.top();
            if(!visited2[x]){
                cnt++;
                scc_dfs(x);
            }
            st.pop();
        }
        if(cnt==1)
        cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
