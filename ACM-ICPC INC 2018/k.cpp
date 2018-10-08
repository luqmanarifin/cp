#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const int inf = 1e9;

vector<int> edge[N];

int d[N], bef[N], ans = inf;

void bfs(int now) {
  fill(d, d + N, inf);
  d[now] = 0;
  queue<int> q;
  q.push(now);
  while (!q.empty() && 2 * d[now] + 2 < ans) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      if (d[it] == inf) {
        d[it] = d[now] + 1;
        q.push(it);
        bef[it] = now;
      } else if (it != bef[now] && bef[it] != now) {
        ans = min(ans, d[now] + d[it] + 1);
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<int> st;
  for (int i = 1; i <= n; i++) {
    st.push_back(i);
  }
  srand(time(0));
  random_shuffle(st.begin(), st.end());
  time_t start = clock();
  for (auto it : st) {
    time_t time_now = clock();
    if ((double) (time_now - start) / CLOCKS_PER_SEC > 0.95) break;
    bfs(it);
  }

  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
