
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

vector<int> edge[N];
bool adj[N][N];
int d[N][N];

int main() {
  int n, m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u][v] = adj[v][u] = 1;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int st = 1; st <= n; st++) {
    for (int i = 1; i <= n; i++) d[st][i] = inf;
    d[st][st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto i : edge[now]) {
        if (d[st][i] > d[st][now] + 1) {
          d[st][i] = d[st][now] + 1;
          q.push(i);
        }
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j++) {
  //     printf("%d %d: %d\n", i, j, d[i][j]);
  //   }
  // }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!adj[i][j]) {
        bool decreased = 0;
        decreased |= (d[s][i] + d[j][t] + 1 < d[s][t]);
        decreased |= (d[t][i] + d[j][s] + 1 < d[s][t]);
        if (!decreased) {
          ans++;
          // printf("ans %d %d\n", i, j);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
