#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> a[N], b[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= k; i++) {
    int t, r, v;
    scanf("%d %d %d", &t, &r, &v);
    if(t == 1) {
      a[r] = make_pair(v, i);
    } else {
      b[r] = make_pair(v, i);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(a[i].second > b[j].second) {
        printf("%d ", a[i].first);
      } else {
        printf("%d ", b[j].first);
      }
    }
    printf("\n");
  }
  return 0;
}
