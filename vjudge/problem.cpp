#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int k;
    scanf("%d %d", &n, &k);
    long long now = 0;
    vector<int> del;
    for (int i = 0; i < n - 1; i++) {
      int size = n - i;
      now = (now + k - 1) % size;
      del.push_back(now);
      now = now % (size - 1);
    }
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      int less = mid;
      for (int i = 0; i < n - 1; i++) {
        if (del[i] < less) {
          less--;
        }
      }
      if (less == 0) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    printf("Case %d: %d\n", tt, l + 1);
  }

  return 0;
}
