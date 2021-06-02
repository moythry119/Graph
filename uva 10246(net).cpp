#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=ml i--)
#define inf 100000000
using namespace std;

int main(){
    int cs=1, n, m, r, u, v, w, q, tcost;
    while(1){
        int total, x, dis[90][90], c[90][90];
        cin>>n>>m>>q;
        if(n==0&&m==0&&q==0) break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) dis[i][j]=0;
                else dis[i][j]=inf;
                c[i][j]=inf;
            }
        }
        fi(1, n){
            cin>>x;
            c[i][i]=x;
        }
        fi(1, m){
            cin>>u>>v>>w;
            dis[u][v]=w;
            dis[v][u]=w;
            c[u][v]=c[v][u]=max(c[u][u], c[v][v]);
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    total=dis[i][k]+dis[k][j];
                    tcost=max(c[i][k], c[k][j]);
                    if(dis[i][j]+c[i][j]>total+tcost){
                        dis[i][j]=total;
                        c[i][j]=tcost;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<endl<<endl<<endl;
             for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<endl<<endl<<endl;
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    total=dis[i][k]+dis[k][j];
                    tcost=max(c[i][k], c[k][j]);
                    if(dis[i][j]+c[i][j]>total+tcost){
                        dis[i][j]=total;
                        c[i][j]=tcost;
                    }
                }
            }
        }
            for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<endl<<endl<<endl;
                for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
         cout<<endl;
        if(cs!=1)cout<<endl;
        cout<<"Case #"<<cs++<<endl;
        fi(1, q){
            cin>>u>>v;
            if(dis[u][v]>=inf) cout<<-1<<endl;
            else cout<<dis[u][v]+c[u][v]<<endl;
        }
    }
    return 0;
}
