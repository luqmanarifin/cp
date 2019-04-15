#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> edge[N];
int s[N];

pair<int, int> dfs(int now) {
  int sum_l = 0, min_r = 2e9, sum_r = 0;
  for (auto it : edge[now]) {
    auto ret = dfs(it);
    sum_l += ret.first;
    sum_r += ret.second;
    min_r = min(min_r, ret.second);
  }
  int mid = edge[now].size();
  if (mid == 0) {
    return make_pair(0, 0);
  }
  int tot = sum_l + sum_r + mid;
  if (s[now] == 0) {
    return make_pair(sum_l, tot - 1 - sum_l);
  } else {
    return make_pair(tot - 1 - min_r, min_r);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", s + i);
  }
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    edge[p].push_back(i);
  }
  auto it = dfs(1);
  cout << it.first + 1 << endl;
  return 0;
}
