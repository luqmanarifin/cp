#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
vector<int> back[N];
int u[N];
int ans[N];

void dfs(int now, int prev) {
  for(auto it : edge[now]) {
    if(it == prev) continue;
    dfs(it, now);
    u[now] += u[it];
  }
  for(auto it : back[now]) {
    if(it == prev) continue;
    dfs(it, now);
    u[now] += u[it] + 1;
  }
}

void finish(int now, int prev, int bring) {
  ans[now] = u[now] + bring;
  for(auto it : edge[now]) {
    if(it == prev) continue;
    finish(it, now, bring + u[now] - u[it] + 1);
  }
  for(auto it : back[now]) {
    if(it == prev) continue;
    finish(it, now, bring + u[now] - u[it] - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    back[b].push_back(a);
  }
  dfs(1, -1);
  finish(1, -1, 0);
  int best = N;
  for(int i = 1; i <= n; i++) {
    best = min(best, ans[i]);
  }
  printf("%d\n", best);
  for(int i = 1; i <= n; i++) {
    if(ans[i] == best) {
      printf("%d ", i);
    }
  }
  return 0;
}
