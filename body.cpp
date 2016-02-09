#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int to[N * N];
vector<int> edge[N];
int bridge, a, b;
bool done[N];

int get_num(int now) {
  done[now] = 1;
  int ret = 1;
  for(auto it : edge[now]) {
    if(it == bridge || it == (bridge ^ 1)) continue;
    if(!done[to[it]]) {
      ret += get_num(to[it]);
    }
  }
  return ret;
}

// 1 valid, 0 gak
int check(int now, int size) {
  done[now] = 1;
  if(now == a || now == b) {
    if(edge[now].size() != size + 1) {
      return 0;
    }
  }
  if(now != a && now != b) {
    if(edge[now].size() != size) {
      return 0;
    }
  }
  for(auto it : edge[now]) {
    if(it == bridge || it == (bridge ^ 1)) continue;
    if(!done[to[it]]) {
      if(!check(to[it], size)) return 0;
    }
  }
  return 1;
}

int check_edge(int num) {
  bridge = num;
  a = to[num];
  b = to[num ^ 1];
  memset(done, 0, sizeof(done));
  int sz_lef = get_num(a);
  memset(done, 0, sizeof(done));
  int sz_rig = get_num(b);
  if(sz_lef != sz_rig) return 0;
  memset(done, 0, sizeof(done));
  int vl = check(a, sz_lef - 1);
  int vr = check(b, sz_rig - 1);
  return vl && vr;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
      edge[i].clear();
    }
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(i + i);
      to[i + i] = v;
      edge[v].push_back(i + i + 1);
      to[i + i + 1] = u;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
      ans += check_edge(i + i);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
