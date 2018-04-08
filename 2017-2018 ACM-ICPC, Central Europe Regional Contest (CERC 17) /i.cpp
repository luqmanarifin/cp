#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], e[N];

int rmq_min(int d[N][20], int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return min(d[l][g], d[r-(1<<g)+1][g]);
}

int rmq_max(int d[N][20], int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(d[l][g], d[r-(1<<g)+1][g]);
}

int a_rmq_min[N][20], a_rmq_max[N][20];
int e_rmq_min[N][20], e_rmq_max[N][20];

map<pair<int, int>, pair<int, int>> mp[2];

pair<int, int> ask(int st, int l, int r) {
  if (mp[st].count(make_pair(l, r))) return mp[st][make_pair(l, r)];
  if (st == 0) {
    int lef = rmq_min(a_rmq_min, l, r);
    int rig = rmq_max(a_rmq_max, l, r);
    if (rig - lef == r - l) {
      return mp[st][{l, r}] = {l, r};
    }
    return mp[st][{l, r}] = ask(st ^ 1, lef, rig);
  } else {
    int lef = rmq_min(e_rmq_min, l, r);
    int rig = rmq_max(e_rmq_max, l, r);
    if (rig - lef == r - l) {
      return mp[st][{l, r}] = {lef, rig};
    }
    return mp[st][{l, r}] = ask(st ^ 1, lef, rig);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    e[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    a_rmq_max[i][0] = a[i];
    a_rmq_min[i][0] = a[i];
    
    e_rmq_max[i][0] = e[i];
    e_rmq_min[i][0] = e[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      a_rmq_min[i][j] = min(a_rmq_min[i][j-1], a_rmq_min[i+(1<<(j-1))][j-1]);
      a_rmq_max[i][j] = max(a_rmq_max[i][j-1], a_rmq_max[i+(1<<(j-1))][j-1]);
      
      e_rmq_min[i][j] = min(e_rmq_min[i][j-1], e_rmq_min[i+(1<<(j-1))][j-1]);
      e_rmq_max[i][j] = max(e_rmq_max[i][j-1], e_rmq_max[i+(1<<(j-1))][j-1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    auto ans = ask(0, l, r);
    printf("%d %d\n", ans.first, ans.second);
  }
  
  return 0;
}
