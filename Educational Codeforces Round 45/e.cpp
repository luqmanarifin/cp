#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const long long inf = 1e18;

int place[N];
int bad[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) place[i] = i;
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    bad[v] = 1;
  }
  place[0] = (bad[0]? -1 : 0);
  for (int i = 1; i < n; i++) {
    if (bad[i]) {
      place[i] = place[i-1];
    } else {
      place[i] = i;
    }
  }
  for (int i = n; i < N; i++) place[i] = place[n - 1];
  
  long long ans = inf;
  for (int i = 1; i <= k; i++) {
    long long cost;
    scanf("%lld", &cost);
    if (bad[0]) continue;
    
    bool can = 1;
    int last = 0;
    int need = 1;
    while (last + i < n) {
      int to = place[last + i];
      if (to <= last) {
        can = 0;
        break;
      } else {
        last = to;
        need++;
      }
    }
    if (can) {
      ans = min(ans, cost * need);
    }
  }
  if (ans >= inf) ans = -1;
  cout << ans << endl;
  return 0;
}

