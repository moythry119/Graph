#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n+1]={0};
    ll p[n];
    for(ll i=0;i<n-1;i++)
    {
        cin>>p[i];
    }
    ll ans[n+1];
    ll j=0,k=0;
    for(ll i=0;i<n-1;i++)
    {
       ll r=abs(p[i]);
       if(a[k]==0)
       {
           if(a[k+r]==0)
           {
               if(p[i]>0)
               {
                   ans[j]=k+1;
                   j++;
                   ans[j]=k+1+r;
                   j++;
               }
               else
               {
                  ans[j]=k+1+r;
                   j++;
                   ans[j]=k+1;
                   j++;
               }
               a[k]=1;
               a[k+r]=1;
               k++;

           }
           else
           {
               if(k+r>n-1)
               {
                   ans[j]=k;
                   j++;
               }
               else
               {
               cout<<"-1"<<endl;
               continue;
               }
           }

       }
       else
       {
           k++;
       }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
