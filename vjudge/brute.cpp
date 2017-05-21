#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N], n;

void upd(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int main() {
  for (int n = 4; n <= 6; n++) {
    for (int k = 1; k <= 10; k++) {
      memset(bit, 0, sizeof(bit));
      int now = 0;
      set<int> s;
      for (int i = 0; i < n; i++) {
        s.insert(i);
        upd(i, 1);
      }
      for (int i = 0; i < n - 1; i++) {
        int size = n - i;
        now = (now + k - 1) % size;
        int l = 0, r = n - 1;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (find(mid) <= now) {
            l = mid + 1;
          } else {
            r = mid;
          }
        }
        s.erase(l);
        upd(l, -1);
        now = now % (size - 1);
      }
      printf("%d %d: %d\n", n, k, *(s.begin()) + 1);
    }
  }

  return 0;
}
