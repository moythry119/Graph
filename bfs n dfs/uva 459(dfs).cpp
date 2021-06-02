
#include<bits/stdc++.h>
using namespace std;

vector<int> ck(1000);
int n;
vector<int>adj[10000];
void dfs(int s)
{
int i;
if(ck[s]==1)
    return;
else
{
ck[s]=1;
//cout<<s<<endl;
}
for(i=0;i<adj[s].size();i++)
{
int u=adj[s][i];
if(ck[u]==0)
{
  dfs(u);
  //n++;

}


}


}
int main()
{
    char edge;
    char input[10];
    char a,b;
    cin>>edge;
    int v=edge-'0'-16;
    while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{

        int x1=a-'0'-16;
        int x2=b-'0'-16;
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);

    }

    int cnt=0;
    for(int i=1; i<=v; i++)
    {
        if(ck[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}



