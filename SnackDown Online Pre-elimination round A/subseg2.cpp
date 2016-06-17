#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int id[N], a[N], b[N];
int to[N];
vector<int> edge[N];

int cnt[N], dad[N];
int comp[N], num_comp, idc[N];
vector<int> e[N];

void dfs_pure(int now) {
  cnt[now] = 1;
  for(auto it : edge[now]) {
    dad[it] = now;
    dfs_pure(it);
    cnt[now] += cnt[it];
  }
}

void dfs(int now) {
  comp[now] = num_comp;
  e[num_comp].push_back(now);
  int p = -1, best = -1;
  for(auto it : edge[now]) {
    if(cnt[it] > best) {
      best = cnt[it];
      p = it;
    }
  }
  if(p == -1) return;
  dfs(p);
  
  for(auto it : edge[now]) {
    if(it == p) continue;
    num_comp++;
    dfs(it);
  }
}

void build_hld(int root) {
  dfs_pure(root);
  dfs(root);
  for(int i = 0; i <= num_comp; i++) {
    for(int j = 0; j < e[i].size(); j++) {
      idc[e[i][j]] = j;
    }
  }
}

int query(int u, int v) {
  int anc = e[comp[u]][0];
  if(anc == v) return idc[u];
  if(anc < v) {
    if(dad[anc] <= v) {
      return idc[u] + 1 + query(dad[anc], v);
    }
    return idc[u];
  }
  int l = 0, r = idc[u];
  while(l < r) {
    int mid = (l + r) >> 1;
    if(e[comp[u]][mid] <= v) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return idc[u] - l;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> all;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    all.push_back(a[i]);
    all.push_back(b[i] + 1);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for(int i = 0; i < all.size(); i++) {
    id[all[i]]++;
    if(i) if (all[i - 1] + 1 < all[i]) {
      id[all[i - 1] + 1]++;
    }
  }
  for(int i = 1; i < N; i++) {
    id[i] += id[i - 1];
  }
  //for(int i = 1; i < 10; i++) printf("%d ", id[i]); printf("\n");
  
  int til = id[N - 1];
  fill(to, to + N, N);
  for(int i = 0; i < n; i++) {
    to[id[a[i]]] = min(to[id[a[i]]], id[b[i] + 1]);
  }
  for(int i = til - 1; i >= 0; i--) {
    to[i] = min(to[i], to[i + 1]);
  }
  //for(int i = 1; i < 10; i++) printf("%d ", to[i]); printf("\n");
  for(int i = 0; i <= til; i++) {
    if(to[i] <= til) {
      edge[to[i]].push_back(i);
    }
  }
  //for(int i = 0; i <= til; i++) for(auto it : edge[i]) printf("%d %d\n", i, it);
  build_hld(til);
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", query(id[l], id[r + 1]));
  }
  return 0;
}