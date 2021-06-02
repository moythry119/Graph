#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll>v[1005];
int ck[1005];


int dfs(int s)
{
int i;
if(ck[s]==1)
{
    return s+1;
}
   // return;
else
{
ck[s]=1;
//cout<<s<<endl;
}
for(i=0;i<v[s].size();i++)
{
int u=v[s][i];

  dfs(u);
  //n++;



}


}

int main()
{
   // ll n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
        v[i].push_back(a[i]);
    }
    for(int i=0;i<n;i++)
    {
      int ans=dfs(i);
      cout<<ans<<" ";
    }

}
