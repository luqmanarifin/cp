#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int active[2 * N], ke[2 * N];
vector<int> edge[N];
int L, R;
int a[N];

int bit[N][2];
long long ans;

void add(int i, int j, int val) {
  for (; i < N; i |= i + 1) {
    bit[i][j] += val;
  }
}

int find(int i, int j) {
  int ret = 0;
  for (i = min(i, N - 1); i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i][j];
  }
  return ret;
}

int find(int l, int r, int j) {
  return find(r, j) - find(l - 1, j);
}

bool done[N];
int to[N];
vector<int> s;

int dfs(int now, int bef) {
  int cnt = 1;
  done[now] = 0;
  to[now] = edge[now].size();
  s.push_back(now);
  for (auto i : edge[now]) {
    if (!active[i]) continue;
    int it = ke[i];
    if (it == bef) continue;
    cnt += dfs(it, now);
  }
  return cnt;
}

int find_center(int now) {
  s.clear();
  int cnt = dfs(now, -1);
  if (cnt <= 2) return -1;
  
  queue<int> q;
  for (auto it : s) {
    if (to[it] <= 1) {
      done[it] = 1;
      q.push(it);
    }
  }
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (auto i : edge[now]) {
      if (!active[i]) continue;
      int it = ke[i];
      to[it]--;
      if (!done[it] && to[it] <= 1) {
        done[it] = 1;
        q.push(it);
      }
    }
  }
  return now;
}

vector<int> st;

void solve(int now, int bef, int cost, int c) {
  st.push_back(cost);
  for (auto i : edge[now]) {
    if (!active[i]) continue;
    int it = ke[i];
    if (it == bef) continue;
    solve(it, now, cost + (c && a[it] < a[now]), a[it] > a[now]);
  }
}

void solve(int now) {
  int from = now;
  now = find_center(now);
  if (now == -1) return;
  
  vector<int> all[2];
  for (auto k : edge[now]) {
    if (!active[k]) continue;
    int it = ke[k];
    st.clear();
    solve(it, now, 0, a[it] > a[now]);
    int j = (a[it] < a[now]);
    for (auto i : st) {
      ans += (L <= i && i <= R);
      ans += find(L - i, R - i, 0);
      ans += find(L - i - j, R - i - j, 1);
    }
    for (auto i : st) {
      add(i, j, 1);
      all[j].push_back(i);
    }
  }
  for (int j = 0; j < 2; j++) {
    for (auto i : all[j]) {
      add(i, j, -1);
    }
  }
  for (auto i : edge[now]) {
    if (!active[i]) continue;
    active[i ^ 1] = 0;
    solve(ke[i]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    
    int n;
    scanf("%d %d %d", &n, &L, &R);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int p = 0;
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      active[p] = 1;
      ke[p] = v;
      edge[u].push_back(p++);
      
      active[p] = 1;
      ke[p] = u;
      edge[v].push_back(p++);
    }
    ans = 0;
    solve(1);
    printf("%lld\n", ans);
  }

  return 0;
}
