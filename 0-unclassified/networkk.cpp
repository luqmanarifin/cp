#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> edge[N], leafs;
int h[N], best;

int dfs(int now, int p) {
  vector<int> num;
  num.push_back(h[now]);
  for(auto it : edge[now]) {
    if(it == p) continue;
    h[it] = h[now] + 1;
    num.push_back(dfs(it, now));
  }
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  if(num.size() == 1) {
    return num[0];
  }
  best = max(best, num[0] + num[1] - 2 * h[now]);
  return num[0];
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      h[i] = 0;
      edge[i].clear();
    }
    leafs.clear();
    best = 0;
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    if(n <= 2) {
      puts("0");
      continue;
    }
    dfs(1, 0);
    cout << n - 1 - best << endl;
  }
  return 0;
}
