#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int l[N], r[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", l + i, r + i);
  int L = 0, R = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    L += l[i];
    R += r[i];
  }
  ans = abs(R - L);
  int p = -1;
  for (int i = 0; i < n; i++) {
    L -= l[i] - r[i];
    R -= r[i] - l[i];
    if (abs(R - L) > ans) {
      ans = abs(R - L);
      p = i;
    }
    L += l[i] - r[i];
    R += r[i] - l[i];
  }
  cout << p + 1 << endl;
  return 0;
}
