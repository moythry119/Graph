#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=m; i--)
using namespace std;

int main(){
    int cs=1, n, u, v, w, m;
    string s;
    while(1){
        int i, j, k, dis[25][25], ans, sum, mn=1000000009;
        map<int, string>mp;
        cin>>n>>m;
        if(n==0) break;
        fi(1, n){
            cin>>s;
            mp[i]=s;
        }
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(i==j)dis[i][j]=0;
                else dis[i][j]=1000000009;
            }
        }
        fi(0, m-1){
            cin>>u>>v>>w;
            dis[u][v]=dis[v][u]=w;
        }
        for(k=1; k<=n; k++){
            for(i=1; i<=n; i++){
                for(j=1; j<=n; j++){
                    dis[i][j]=min(dis[i][j], (dis[i][k]+dis[k][j]));
                }
            }
        }
        for(i=1; i<=n; i++){
            sum=0;
            for(j=1; j<=n; j++){
                sum=sum+dis[i][j];
            }
            if(mn>sum){
                mn=sum; ans=i;
            }
        }
        cout<<"Case #"<<cs++<<" : "<<mp[ans]<<endl;
    }
    return 0;
}
