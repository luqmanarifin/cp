#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long a[N];
vector<pair<int, long long>> edge[N];
int n;

// need, supply
pair<long long, long long> dfs(int now) {
  long long need = max(-a[now], 0LL);
  long long supply = max(a[now], 0LL);
  for (auto it : edge[now]) {
    auto ret = dfs(it.first);
    if (ret.first > inf / it.second) {
      puts("NO");
      exit(0);
    } else {
      need += ret.first * it.second;
    }
    if (need > inf) {
      puts("NO");
      exit(0);
    }
    supply += ret.second;
  }
  if (need < supply) {
    return {0, supply - need};
  } else if (need > supply) {
    return {need - supply, 0};
  } else {
    return {0, 0};
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 1; i <= n; i++) {
    long long v;
    scanf("%I64d", &v);
    a[i] -= v;
  }
  for (int i = 2; i <= n; i++) {
    int x, k;
    scanf("%d %d", &x, &k);
    edge[x].emplace_back(i, k);
  }
  auto it = dfs(1);
  if (it.first > 0) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
