
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = n;
  for (int t = n / 2; t >= 1; t--) {
    bool ok = 1;
    for (int i = 0; i < t; i++) {
      if (s[i] != s[t + i]) {
        ok = 0;
      }
    }
    if (ok) {
      ans = min(ans, n - t + 1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
