#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long sll;
#define count__ __builtin_popcount
#define mod 1000000007
#define sf(x) scanf("%d",&x)
#define sff(x,y) scanf("%d%d",&x,&y)
#define sfff(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d\n",x)
#define pff(x,y) printf("%d %d\n",x,y)
#define pfff(x,y,z) printf("%d %d %d\n",x,y,z)

using namespace std;

struct point {
 int x , y;
 point () {}
 point (int x_ , int y_) {
  x = x_;
  y = y_;
 }
};

queue < point > Q;
bool visited[10][10];
int level[10][10];
int fx[] = {1 , 0 , -1 , 0};
int fy[] = {0 , 1 , 0 , -1};
int hx_move[] = {+2 , +2 , +1 , -1 , -2 , -2 , -1 , +1}; /// knight move in x axis;
int hy_move[] = {-1 , +1 , +2 , +2 , +1 , -1 , -2 , -2}; /// knight move in y axis;

void goooo (int sx , int sy) {
 Q.push(point (sx , sy));
 visited[sx][sy] = 1;
 level[sx][sy] = 0;
 while (!Q.empty()) {
  point top = Q.front();
  for (int i = 0; i < 8; i++) {
   int tx = top.x + hx_move[i];
   int ty = top.y + hy_move[i];
   if (tx >= 0 && tx < 8 and ty >= 0
        && ty < 8 and !visited[tx][ty]) {
    visited[tx][ty] = 1;
    level[tx][ty] = level[top.x][top.y] + 1;
    Q.push(point (tx , ty));
   }
  }
  Q.pop();
 }
}

int main () {
 char pos1[3] , pos2[3];
 while (cin >> pos1 >> pos2) {
  memset (visited , 0 , sizeof (visited));
  int a = pos1[0] - 'a';
  int b = pos1[1] - '0';
  int c = pos2[0] - 'a';
  int d = pos2[1] - '0';
  goooo (a , b - 1);
  cout << "To get from " << pos1 << " to " << pos2 << " takes " << level[c][d - 1] << " knight moves." << endl;
 }
}
