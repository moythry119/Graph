#include<bits/stdc++.h>
#define N 105

using namespace std;

int n;
bool Free[N];
vector <int> a[N];
int x;

int BFS(int u) {
    queue <int> Q;
    Q.push(u); Free[u] = false;
    int i, v, dem = 0;
    while (!Q.empty()) {
        u = Q.front();
        for (i=0; i<a[u].size(); i++) {
            v = a[u][i];
            if (Free[v]) {
                Q.push(v);
                dem++;
                Free[v] = false;
            }
        }
        x=u;
        Q.pop();
    }
    return dem;
}

int main() {
    int i, t, p,q;
    while (scanf("%d", &n) && n) {
        for (i=1; i<=n; i++) {
          //  a[i].clear();

               scanf("%d", &t);

                while(scanf("%d %d", &p,&q) && p &&q)
                {
                a[p].push_back(q);
                }

                memset(Free, true, n+2);
                int temp = BFS(t);
                cout<<x<<" "<<temp<<endl;

        }

       // printf("%d\n", u);
    }
}

