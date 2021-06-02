
#include<bits/stdc++.h>
using namespace std;

vector<int>adj[10000];
int visited[10000];

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                Q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main()
{
    char edge;
    char input[10];
    char a,b;
    cin>>edge;
    int v=edge-'A';
    while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{

        int x1=a-'A';
        int x2=b-'B';
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);

    }

    int cnt=0;
    for(int i=1; i<=v; i++)
    {
        if(visited[i]==0)
        {
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}

