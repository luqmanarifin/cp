
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int bit[N], done[N];

int get(int l, int r) {
  if (l > r) return 0;
  if (r < 0) return 0;
  return bit[r] - (l? bit[l - 1] : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));
    memset(bit, 0, sizeof(bit));

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (!done[v]) {
        done[v] = 1;
        bit[v] = 1;
      }
    }
    for (int i = 1; i < N; i++) bit[i] += bit[i-1];

    int l = 0, r = N - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      int need = mid - get(0, mid - 1);
      if (need > k) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    printf("%d\n", l);
  } 

  return 0;
}
