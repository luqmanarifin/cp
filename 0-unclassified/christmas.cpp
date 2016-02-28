#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int rmq[N][20], h[N], pos[N];
int cnt, n;

void dfs(int now, int p) {
  h[now] = h[p] + 1;
  pos[now] = cnt;
  rmq[cnt][0] = now;
  ++cnt;
  for(auto it : edge[now]) {
    if(it == p) continue;
    dfs(it, now);
    rmq[cnt][0] = now;
    ++cnt;
  }
}

void build_rmq() {
  cnt = 0;
  dfs(0, N - 1);
  for(int j = 1; (1 << j) <= cnt; j++) {
    for(int i = 0; i + (1 << j) <= cnt; i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j - 1]]? rmq[i][j - 1] : rmq[i+(1<<(j-1))][j - 1]);
    }
  }
}

int lca(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    build_rmq();
    int q;
    scanf("%d", &q);
    set<int> r;
    while(q--) {
      char c; int p;
      scanf(" %c %d", &c, &p);
      if(c == '+') {
        r.insert(pos[p]);
      } else {
        r.erase(pos[p]);
      }
      if(r.empty()) {
        puts("-1");
      } else {
        auto lef = r.begin();
        auto rig = r.end();
        rig--;
        printf("%d\n", lca(*lef, *rig));
      }
    }
  }
  
  return 0;
}
