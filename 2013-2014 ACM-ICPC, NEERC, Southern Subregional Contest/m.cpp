#include <bits/stdc++.h>

using namespace std;

const int N = 905;
const int M = 2e5 + 5;
const int inf = 1e9;

int d[N][N][2];
int a[M], b[M];
vector<int> edge[N];

int main() {
  ios_base::sync_with_stdio(false);
  
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) edge[i].clear();
    
    for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
      edge[a[i]].push_back(b[i]);
    }
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j][0] = d[i][j][1] = inf;
      }
    }
    for (int s = 1; s <= n; s++) {
      d[s][s][0] = d[s][s][1] = 0;
      queue<pair<int, int>> q;
      q.emplace(s, 0);
      while (!q.empty()) {
        int now, t;
        tie(now, t) = q.front();
        q.pop();
        for (auto it : edge[now]) {
          for (int i = 0; i < 2; i++) {
            if (d[s][it][i] > d[s][now][t] + 1) {
              d[s][it][i] = d[s][now][t] + 1;
              q.emplace(it, i);
              break;
            }
          }
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int ans = d[a[i]][b[i]][1];
      if (ans == inf) ans = 0;
      printf("%d%c", ans, " \n"[i == m - 1]);
    }
  }

  return 0;
}
