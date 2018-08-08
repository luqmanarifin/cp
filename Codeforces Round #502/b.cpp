#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[4];
char a[N], b[N];

int main() {
  int n;
  scanf("%d %s %s", &n, a, b);
  for (int i = 0; i < n; i++) {
    int v = 0;
    if (a[i] == '1') v |= 2;
    if (b[i] == '1') v |= 1;
    cnt[v]++;
  }
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int p = i / 2, q = i % 2;
      int r = j / 2, s = j % 2;
      bool left = (p | q) != (r | q);
      bool righ = (r | s) != (p | s);
      if (left || righ) {
        ans += 1LL * cnt[i] * cnt[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
