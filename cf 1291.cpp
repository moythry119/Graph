#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 10006
int vis[SIZE];
int dur[SIZE];
int low[SIZE];
int art[SIZE];
int counter;
int parent[SIZE];
int f[SIZE];
vector < vector <int> > g;
int find_articulation(int x)
{
	int child;
	int y;

	counter++;
	vis[x] = 1;
	child = 0;

	dur[x] = low[x] = counter;

	for (int i = 0; i < g[x].size(); i++) {
		y = g[x][i];
		child++;

		if(vis[y] == 0) {
			parent[y] = x;
			find_articulation(y);
			low[x] = min(low[x], low[y]);

           if(child > 1 and parent[x] == -1) {
				f[x] = 1;
				cout<<x<<endl;
			}

			if(parent[x] != -1 and low[y] >= dur[x]) {
				f[x] = 1;
			}

			}


		else {
			if(y != parent[x]) {
				low[x] = min(low[x], dur[y]);
			}
		}

	}
     // if(parent[x] == -1 and child > 1) f[x] = 1;

}
int main()
{
    int t;
    cin>>t;
    for (int tc=1;tc<=t;tc++)
    {
              int n,m;
      cin>>n>>m;
    vector < vector <int> > sp(n+2);
        memset(parent, -1, sizeof parent);
		memset(vis, 0, sizeof vis);
        memset(dur, 0, sizeof dur);
        memset(low, 0, sizeof low);
        memset(f, 0, sizeof f);
          swap(g,sp);
      //  memset(g, 0, sizeof g);
        //g.clear();




      for(int i=0;i<m;i++)
      {
          int x,y;
          cin>>x>>y;
      //    x--;
       //   y--;

          g[x].push_back(y);
          g[y].push_back(x);

      }

        int ans=0;
		for (int i = 0; i < n; i++) {

			if(g[i].size()==1)
            {
                ans++;
            }
		}
		if(ans==0)
        {
         cout<<"Case "<<tc<<": "<<0<<endl;
         continue;
        }


      cout<<"Case "<<tc<<": "<<ans-1<<endl;
    }
}

