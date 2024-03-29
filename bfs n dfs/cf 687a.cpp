#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
const int N = 120021;

vector <int> vc[2];
vector <int> g[N];
int mark[N];

bool dfs(int v, int color = 2)
{
	mark[v] = color;
	vc[color - 1].push_back(v);
	for(int u : g[v])
	{
		if(!mark[u] && dfs(u, 3 - color))
				return 1;
		if(mark[u] != 3 - color)
			return 1;
	}
	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u = in() - 1;
		int v = in() - 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
		{
		     if(g[i].empty())
		          continue;
		     if(dfs(i))
			{
				cout << -1 << endl;
				return 0;
			}
		}
	for(int i = 0; i < 2; i++)
	{
		cout << vc[i].size() << endl;
		for(int v : vc[i])
			cout << v + 1 << " ";
		cout << endl;
	}
