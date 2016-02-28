#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
long long a[N];

pair<long long, long long> dfs(int now, int prev) {
  long long up = 0, down = 0;
  for(auto it : edge[now]) {
    if(it == prev) {
      continue;
    }
    pair<long long, long long> tmp = dfs(it, now);
    up = max(up, tmp.first);
    down = max(down, tmp.second);
  }
  long long val = a[now] + up - down;
  if(val < 0) up += -val;
  else down += val;
  return make_pair(up, down);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  pair<long long, long long> ret = dfs(1, -1);
  cout << ret.first + ret.second << endl;
  return 0;
}
