#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int b[N], w[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d %s", &n, &k, s + 1);
    for (int i = 0; i <= n; i++) b[i] = w[i] = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = b[i - 1];
      w[i] = w[i - 1];
      if (s[i] == 'B') b[i]++;
      if (s[i] == 'W') w[i]++;
    }
    int ans = n;
    for (int i = k; i <= n; i++) {
      ans = min(ans, w[i] - w[i - k]);
    }
    printf("%d\n", ans);
  }

  return 0;
}
