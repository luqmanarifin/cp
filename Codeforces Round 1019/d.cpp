#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int l[N], r[N], a[N];
vector<int> edge[N];
bool vis[N];
int ans[N], to[N];

void remove(int x) {
  int lef = l[x];
  int rig = r[x];
  r[lef] = rig;
  l[rig] = lef;
}

void add(int x, int y, int d) {
  // printf("%d %c %d\n", x, d == 1? '<' : '>', y);
  if (d == 1) {
    edge[x].push_back(y);
  } else {
    edge[y].push_back(x);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        a[i] = mx + 1;
      }
    }
    for (int i = 0; i <= n + 1; i++) {
      l[i] = i - 1;
      r[i] = i + 1;
      edge[i].clear();
      vis[i] = 0;
      to[i] = 0;
    }
    for (int k = 1; k <= mx; k++) {
      // printf("starting %d\n", k);
      vector<int> p;
      for (int i = r[0]; i <= n; i = r[i]) {
        p.push_back(i);
      }
      int d = 0;
      if (k % 2) {
        if (a[p[0]] > k) {
          d = 1;
        } else {
          d = 0;
        }
      } else {
        if (a[p[0]] > k) {
          d = 0;
        } else {
          d = 1;
        }
      }
      // printf("start %d\n", d);
      for (int i = 1; i < p.size(); i++) {
        if (a[p[i]] == k) {
          add(p[i-1], p[i], d);
          continue;
        }
        if (k % 2) {
          add(p[i-1], p[i], 0);
          d = 1;
        } else {
          add(p[i-1], p[i], 1);
          d = 0;
        }
      }
      for (auto it : p) if (a[it] == k) remove(it);
    }
    for (int i = 1; i <= n; i++) {
      for (auto it : edge[i]) {
        to[it]++;
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (to[i] == 0) {
        vis[i] = 1;
        q.push(i);
      }
    }
    int cur = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      ans[now] = ++cur;
      for (auto it : edge[now]) {
        to[it]--;
        if (to[it] == 0 && !vis[it]) {
          vis[it] = 1;
          q.push(it);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        assert(0);
        ans[i] = ++cur;
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", ans[i], i == n? '\n' : ' ');
    }
  }

  return 0;
}
