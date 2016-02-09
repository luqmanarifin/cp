#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> edge[N];

// node i height nya berapa
int h[N];
int node[N];

// di posisi lca node keberapa
int t, at[N * 3];

// node i posisinya dimana
int lef[N * 3], rig[N * 3];

// sparse table
int tab[N * 3][20];
int lg[N * 3];

void dfs(int now, int prev) {
  lef[now] = rig[now] = t;
  at[t++] = now;
  h[now] = h[prev] + 1;
  node[now] = 1;
  for(auto it : edge[now]) {
    if(it == prev) continue;
    dfs(it, now);
    rig[now] = t;
    at[t++] = now;
    node[now] += node[it];
  }
}

void build() {
  dfs(1, 0);
  for(int i = 0; i < t; i++) {
    tab[i][0] = i;
  }
  for(int i = 0; (1 << i) < 3 * N; i++) {
    lg[1 << i] = i;
  }
  for(int i = 1; i < 3 * N; i++) {
    if(lg[i]) continue;
    lg[i] = lg[i - 1];
  }
  for(int j = 1; (1 << j) <= t ; j++) {
    for(int i = 0; i + (1 << j) <= t; i++) {
      if(h[at[tab[i][j - 1]]] < h[at[tab[i + (1 << (j - 1))][j - 1]]]) {
        tab[i][j] = tab[i][j - 1];
      } else {
        tab[i][j] = tab[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

int rmq(int i, int j) {
  int logg = lg[j - i + 1];
  return h[at[tab[i][logg]]] < h[at[tab[j-(1<<logg)+1][logg]]]? tab[i][logg] : tab[j-(1<<logg)+1][logg];
}

int lca(int u, int v) {
  return at[rmq(min(lef[u], lef[v]), max(lef[u], lef[v]))];
}

int dist(int u, int v) {
  int root = lca(u, v);
  return abs(h[root] - h[u]) + abs(h[root] - h[v]);
}

// nyari banyak node dari center ke arah u (center exclusive)
int get(int c, int u) {
  if(lef[c] <= lef[u] && lef[u] <= rig[c]) {
    int l = lef[c], r = lef[u];
    while(l < r) {
      int mid = (l + r) >> 1;
      if(lca(at[mid], u) == c) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    //printf("bawah %d\n", at[l]);
    return node[at[l]];
  }
  return n - node[c];
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  build();
  
  int k;
  scanf("%d", &k);
  while(k--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(dist(a, b) % 2) {
      puts("0");
      continue;
    }
    if(a == b) {
      printf("%d\n", n);
      continue;
    }
    if(lef[a] > lef[b]) swap(a, b);
    int l = lef[a], r = lef[b];
    while(l < r) {
      int mid = (l + r) >> 1;
      if(dist(a, at[mid]) < dist(at[mid], b)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    int center = at[l];
    if(h[lca(a, center)] > h[lca(center, b)]) {
      center = lca(a, center);
    } else {
      center = lca(center, b);
    }
    //printf("center %d\n", center);
    printf("%d\n", n - get(center, a) - get(center, b));
  }
  return 0;
}
