#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int T, m, n, a, b;
int x[] = { -1, 0, 1 }, y[] = { 0, -1, 0 };
char inp[100], graph[100][100], iehova[] = { 'I', 'E', 'H', 'O', 'V', 'A', '#' };
string path[] = { "left", "forth", "right" };

void dfs(int i, int j, int s) {
    if(graph[i][j] == '#') {
        cout << endl;
        return;
    }

    for(int k = 0; k < 3; k++)
        if(j + x[k] >= 0 && j + x[k] < n && i + y[k] >= 0)
            if(graph[i + y[k]][j + x[k]] == iehova[s]) {
                cout << path[k];
                if(s < 6) cout << " ";
                dfs(i + y[k], j + x[k], s + 1);
            }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d\n", &m, &n);
        for(int i = 0; i < m; i++) {
            gets(inp);
            strcpy(graph[i], inp);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(graph[i][j] == '@') a = i, b = j;

        dfs(a, b, 0);
    }
}
