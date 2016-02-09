#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int good[N];
int t[N], x[N], y[N];

// 3 query
int to[N];

// 2 queery - who get i document
int doc[N];

// which query ask about i document
vector<int> about[N];
vector<int> edge[N];

vector<int> ask[N];
set<int> st;
int par[N];
bool have[N];
int ans[N];

void dfs(int now) {
  st.insert(now);
  for(auto id : ask[now]) {
    int dad = to[id];
    good[id] = st.count(dad);
  }
  for(auto it : edge[now]) dfs(it);
  st.erase(now);
}

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int id = 0;
  for(int it = 1; it <= m; it++) {
    scanf("%d", t + it);
    if(t[it] == 1) {
      scanf("%d %d", x + it, y + it);
      edge[y[it]].push_back(x[it]);
      have[x[it]] = 1;
    } else if(t[it] == 2) {
      ++id;
      scanf("%d", doc + id);
    } else {
      int d;
      scanf("%d %d", to + it, &d);
      about[d].push_back(it);
      ask[doc[d]].push_back(it);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(!have[i]) {
      dfs(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    par[i] = i;
  }
  id = 0;
  for(int i = 1; i <= m; i++) {
    if(t[i] == 1) {
      merge(x[i], y[i]);
    } else if(t[i] == 2) {
      ++id;
      for(auto q : about[id]) {
        int xx = doc[id];
        int yy = to[q];
        ans[q] = good[q] && find(xx) == find(yy);
      }
    } else {
      puts(ans[i]? "YES" : "NO");
    }
  }
  
  return 0;
}
