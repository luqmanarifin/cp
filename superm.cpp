#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

// 0 from, 1 balik
vector<int> dp[N][2], nice[N];
vector<int> lama[N], edge[N];
bool bad[N];

bool dfs(int now, int p) {
  bool ada = 0;
  for(int i = 0; i < lama[now].size(); i++) {
    int it = lama[now][i];
    if(it == p) continue;
    nice[now][i] = dfs(it, now);
    ada |= nice[now][i];
  }
  return ada || bad[now];
}

void complete(int now, int p, int st) {
  if(st) {
    edge[now].push_back(p);
    edge[p].push_back(now);
  }
  int cnt = 0;
  for(int i = 0; i < lama[now].size(); ++i) {
    int it = lama[now][i];
    if(it == p) continue;
    cnt += nice[now][i];
  }
  for(int i = 0; i < lama[now].size(); ++i) {
    int it = lama[now][i];
    if(it == p) continue;
    if(nice[now][i]) {
      complete(it, now, cnt >= 2 || st || bad[now]);
    }
  }
}

int find(int now, int p, int st, int id) {
  if(dp[p][st][id] != -1) return dp[p][st][id];
  if(st == 0) {
    
    bool ada = 0;
    int& ret = dp[p][st][id] = 1;
    for(int i = 0; i < edge[now].size(); i++) {
      if(edge[now][i] == p) continue;
      ada = 1;
      ret += find(edge[now][i], now, 1, i);
    }
    if(!ada) return ret;
    
    int mini = inf;
    for(int i = 0; i < edge[now].size(); i++) {
      if(edge[now][i] == p) continue;
      mini = min(mini, find(edge[now][i], now, 0, i) - find(edge[now][i], now, 1, i));
    }
    ret += mini;
    return ret;
    
  } else {
    
    int& ret = dp[p][st][id] = 2;
    for(int i = 0; i < edge[now].size(); i++) {
      if(edge[now][i] == p) continue;
      ret += find(edge[now][i], now, 1, i);
    }
    return ret;
    
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    lama[u].push_back(v);
    lama[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    nice[i].resize(lama[i].size());
  }
  for(int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    bad[v] = 1;
  }
  dfs(1, 0);
  complete(1, 0, 0);
  
  //puts("ADUH");
  for(int i = 1; i <= n; i++) {
    dp[i][0].resize(edge[i].size());
    dp[i][1].resize(edge[i].size());
    for(int j = 0; j < edge[i].size(); j++) {
      dp[i][0][j] = -1;
      dp[i][1][j] = -1;
    }
    sort(edge[i].begin(), edge[i].end());
    /*
    for(auto it : edge[i]) {
      printf("%d %d\n", i, it);
    }
    */
  }
  int ans = inf, p = -1;
  bool alone = 1;
  for(int i = 1; i <= n; i++) {
    //printf("size %d %d\n", i, edge[i].size());
    if(edge[i].size() == 0) {
      continue;
    }
    alone = 0;
    //printf("cok %d\n", i);
    int cur = 0;
    for(int j = 0; j < edge[i].size(); j++) {
      cur += find(edge[i][j], i, 1, j);
    }
    //printf("%d sementara %d\n", i, cur);
    int mini = inf;
    for(int j = 0; j < edge[i].size(); j++) {
      mini = min(mini, find(edge[i][j], i, 0, j) - find(edge[i][j], i, 1, j));
    }
    cur += mini;
    //printf("%d hasil %d\n", i, cur);
    if(cur < ans) {
      ans = cur;
      p = i;
    } else if(cur == ans) {
      p = min(p, i);
    }
  }
  if(alone) {
    for(int i = 1; i <= n; i++) {
      if(bad[i]) {
        printf("%d\n0\n", i);
      }
    }
  } else {
    printf("%d\n%d\n", p, ans);
  }
  return 0;
}
