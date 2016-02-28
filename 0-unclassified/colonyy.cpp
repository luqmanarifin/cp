#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

vector<int> edge[N];
bool done[N];
int ans[N];

int dfs(int now) {
  int ret = 0;
  for(auto it : edge[now]) {
    ret += dfs(it);
  }
  ans[now] = ret;
  return ret + 1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[v].push_back(u);
    done[u] = 1;
  }
  for(int i = 1; i <= n; i++) {
    if(!done[i]) {
      dfs(i);
    }
  }
  int p = -1, mk = -1;
  for(int i = 1; i <= n; i++) {
    if(ans[i] > mk) {
      mk = ans[i];
      p = i;
    }
  }
  cout << p << endl;
  return 0;
}
