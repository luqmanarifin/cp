#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int ax[MAXN+5], ay[MAXN+5], vis[MAXN+5];
vector<int> E[MAXN+5];
vector<pair<int,int> > C[MAXN+5];
vector<int> nodes;
void dfs(int x, int y, int v)
{
   if (vis[v]) return;
   nodes.push_back(v);
   vis[v] = 1;
   ax[v] = x, ay[v] = y;
   for (int i = 0; i < E[v].size(); ++i) {
     int dx = C[v][i].first, dy = C[v][i].second;
     int u = E[v][i];
     dfs(x+dx,y+dy,u);
   }
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
      int a,b,dx,dy;
      scanf("%d%d%d%d", &a,&b,&dx,&dy);
      E[a].push_back(b);
      C[a].push_back(make_pair(dx,dy));
      E[b].push_back(a);
      C[b].push_back(make_pair(-dx,-dy));
    }
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        dfs(0,0,i);
        int lx = 0, ly = 0;
        for (int j = 0; j < nodes.size(); ++j) {
          int v = nodes[j];
          lx = min(lx, ax[v]);
          ly = min(ly, ay[v]);
        }
        for (int j = 0; j < nodes.size(); ++j) {
          int v = nodes[j];
          ax[v] -= lx;
          ay[v] -= ly;
        }
        nodes.clear();
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d %d\n", ax[i], ay[i]);
    }
  return 0;
}
