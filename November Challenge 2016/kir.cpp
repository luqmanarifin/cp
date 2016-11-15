#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e4 + 5;
int CNT;

int edges[N];
vector<int> edge[N];
int active[N];
int L, R;
int a[N];
 
int bit[N][2];
long long ans;
 
void add(int i, int j, int val) {
  for (; i < CNT; i |= i + 1) {
    bit[i][j] += val;
  }
}
 
int find(int i, int j) {
  int ret = 0;
  for (i = min(i, CNT - 1); i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i][j];
  }
  return ret;
}
 
int find(int l, int r, int j) {
  return find(r, j) - find(l - 1, j);
}
 
bool done[N];
int to[N];
int s[N], ps;
 
int dfs(int now, int bef) {
  int cnt = 1;
  done[now] = 0;
  to[now] = edges[now];
  s[ps++] = now;
  for (auto it : edge[now]) {
    if (!active[it]) continue;
    if (it == bef) continue;
    cnt += dfs(it, now);
  }
  return cnt;
}
 
int find_center(int now) {
  ps = 0;
  CNT = dfs(now, -1);
  //printf("dfs %d %d\n", now, cnt);
  if (CNT <= 2) return -1;
  CNT = (CNT + 1) / 2;
  //printf("s: "); for (auto it : s) printf("%d ", it); printf("\n");
  
  queue<int> q;
  for (int i = 0; i < ps; i++) {
    int it = s[i];
    if (to[it] <= 1) {
      done[it] = 1;
      q.push(it);
    }
  }
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      if (!active[it]) continue;
      to[it]--;
      if (!done[it] && to[it] <= 1) {
        done[it] = 1;
        q.push(it);
      }
    }
  }
  return now;
}
 
int st[N], pst;
 
void solve(int now, int bef, int cost, int c) {
  st[pst++] = cost;
  for (auto it : edge[now]) {
    if (!active[it]) continue;
    if (it == bef) continue;
    solve(it, now, cost + (c && a[it] < a[now]), a[it] > a[now]);
  }
}
 
void solve(int now) {
  //puts("");
  //printf("solve %d %lld\n", now, ans);
  
  int from = now;
  now = find_center(now);
  if (now == -1) return;
  //printf("root %d from %d\n", now, from);
  
  vector<int> all[2];
  for (auto it : edge[now]) {
    if (!active[it]) continue;
    
    pst = 0;
    solve(it, now, 0, a[it] > a[now]);
    int j = (a[it] < a[now]);
    for (int k = 0; k < pst; k++) {
      int i = st[k];
      ans += (L <= i && i <= R);
      ans += find(L - i, R - i, 0);
      ans += find(L - i - j, R - i - j, 1);
    }
    //printf("from %d %d: ", it, j);
    for (int k = 0; k < pst; k++) {
      int i = st[k];
      add(i, j, 1);
      all[j].push_back(i);
      //printf("%d ", i);
    }
    //printf("\n");
  }
  for (int j = 0; j < 2; j++) {
    for (auto i : all[j]) {
      add(i, j, -1);
    }
  }
  active[now] = 0;
  for (auto it : edge[now]) {
    if (!active[it]) continue;
    edges[it]--;
    solve(it);
  }
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(edges, 0, sizeof(edges));
    for (int i = 0; i < N; i++) edge[i].clear();
    for (int i = 0; i < N; i++) active[i] = 1;
    
    int n;
    scanf("%d %d %d", &n, &L, &R);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
      edges[u]++;
      edges[v]++;
    }
    ans = 0;
    solve(1);
    printf("%lld\n", ans);
  }
 
  return 0;
}