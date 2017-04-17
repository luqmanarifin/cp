#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int holy[N];
int now[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int val;
    scanf("%d", &val);
    holy[val] = 1;
  }
  now[1] = 1;
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (holy[u] && now[u]) continue;
    if (holy[v] && now[v]) continue;
    swap(now[u], now[v]);
  }
  for (int i = 1; i <= n; i++) {
    if (now[i]) cout << i << endl;
  }
  return 0;
}
