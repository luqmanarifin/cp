#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N], ans;
int a[N];

void dfs(int now, int prev) {
  bool no = 1;
  for(auto it : edge[now]) {
    if(it == prev) continue;
    no = 0;
    dfs(it, now);
  }
  if(no) {
    ans.push_back(now);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    edge[a[i]].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    if(a[i] == 0) {
      dfs(i, 0);
    }
  }
  sort(ans.begin(), ans.end());
  for(auto it : ans) printf("%d ", it);
  return 0;
}