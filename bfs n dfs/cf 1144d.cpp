#include<bits/stdc++.h>
using namespace std;
const int N=2*(1e5)+5;
vector<int> a;
map<int,int> m;
int main(){
    int n,ans=0,x,key;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
        m[x]+=1;
        if (m[x]>ans){
            ans=m[x];
            key=x;
        }
    }
    int pos=find(a.begin(),a.end(),key)-a.begin();
    cout<<n-ans<<endl;
    for(int i=pos-1;i>=0;i--){
        cout<<1+(a[i]>a[i+1])<<" "<<i+1<<" "<<i+2<<" "<<endl;
        a[i]=a[i+1];
    }
    for(int i=0;i<n-1;i++){
        if (a[i+1]!=key){
            cout<<1+(a[i+1]>a[i])<<" "<<i+2<<" "<<i+1<<" "<<endl;
            a[i+1]=a[i];
        }
    }
}
