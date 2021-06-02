#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        //ans;
        cin>>a[i];
        if(m>0 || k>0)
        {
        if(a[i]==1 && m>0)
        {
            m--;
        }
        else if(a[i]==2)
        {
       // int j=max(k,m);
        //if(j>0)
            k--;
        }
        }
        if((m==0 && a[i]==2) || (k==0&&a[i]==1))
        {
                        ans++;
        }
    //cout<<m<<k<<endl;
    }
    cout<<ans<<endl;
}
