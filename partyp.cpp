#include <bits/stdc++.h>

using namespace std;

int ans;
int par[2005];
vector<int> edge[2005];

void dfs(int now, int c) {
  ans = max(ans, c);
  for(auto it : edge[now]) {
    dfs(it, c + 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", par + i);
    if(par[i] != -1) {
      edge[par[i]].push_back(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(par[i] == -1) {
      dfs(i, 1);
    }
  } 
  cout << ans << endl;
  return 0;
}
