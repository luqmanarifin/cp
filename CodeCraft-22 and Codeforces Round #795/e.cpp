#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int lef[N], rig[N], c[N];
vector<int> in[N];

int til[2][N];
set<int> cur[2];
set<int> out[2][N];
int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int at, int u, int v) {
  u = find(u);
  v = find(v);

  // destroy u
  for (int i = 0; i < 2; i++) {
    cur[i].erase(u);
    if (til[i][u] >= 0) {
      out[i][til[i][u]].erase(u);
    }
  }

  // update v
  for (int i = 0; i < 2; i++) {
    if (til[i][u] > til[i][v]) {
      if (til[i][v] != -1) {
        out[i][til[i][v]].erase(v);
      }
      out[i][til[i][u]].insert(v);
      til[i][v] = til[i][u];
    }
    if (til[i][v] >= at) cur[i].insert(v);
  }
  par[u] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", c + i, lef + i, rig + i);
      s.insert(lef[i]);
      s.insert(rig[i]);
    }
    // init
    int cnt = 0;
    for (auto it : s) m[it] = cnt++;
    for (int i = 0; i < n; i++) {
      lef[i] = m[lef[i]];
      rig[i] = m[rig[i]];
      in[lef[i]].push_back(i);
      til[c[i]][i] = rig[i];
      til[c[i]^1][i] = -1;
      par[i] = i;
    }

    for (int i = 0; i < s.size(); i++) {
      // process in
      for (auto it : in[i]) {
        cur[c[it]].insert(it);
        out[c[it]][rig[it]].insert(it);
        vector<int> tmp;
        for (auto other : cur[c[it] ^ 1]) tmp.push_back(other);
        for (auto other : tmp) {
          merge(i, it, other);
        }
      }

      // process out
      for (int j = 0; j < 2; j++) {
        for (auto it : out[j][i]) {
          cur[j].erase(it);
        }
      }
    }
    set<int> comp;
    for (int i = 0; i < n; i++) comp.insert(find(i));
    printf("%d\n", comp.size());

    // clear
    for (int i = 0; i < s.size(); i++) {
      in[i].clear();
    }
    for (int j = 0; j < 2; j++) {
      cur[j].clear();
      for (int i = 0; i < s.size(); i++) {
        out[j][i].clear();
      }
    }

  }

  return 0;
}
