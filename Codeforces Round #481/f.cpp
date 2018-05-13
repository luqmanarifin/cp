#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int a[N], sorted[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), sorted[i] = a[i];
  sort(sorted + 1, sorted + 1 + n);
  while (k--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    int ans = lower_bound(sorted + 1, sorted + 1 + n, a[i]) - sorted - 1;
    for (auto it : edge[i]) {
      if (a[it] < a[i]) {
        ans--;
      }
    }
    printf("%d ", ans);
  }
  return 0;
}
