#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

vector<int> edge[N];
int h[N], to[N];

void clear(int n) {
  for (int i = 1; i <= n; i++) {
    edge[i].clear();
    h[i] = 0;
    to[i] = 0;
  }
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      to[i] = edge[i].size();
      if (edge[i].size() <= 1) {
        q.push(i);
        h[i] = 1;
      }
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      // printf("now %d: %d\n", now);
      for (auto it : edge[now]) {
        if (h[it] == 0) {
          to[it]--;
          if (to[it] <= 1) {
            h[it] = h[now] + 1;
            q.push(it);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (h[i] > k) ans++;
    }
    printf("%d\n", ans);

    clear(n);
  }

  return 0;
}
