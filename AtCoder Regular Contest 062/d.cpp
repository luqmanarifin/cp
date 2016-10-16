#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int p = 0, g = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'g') {
      if (p + 1 <= g) {
        p++;
        ans++;
      } else {
        g++;
      }
    } else {
      if (p + 1 <= g) {
        p++;
      } else {
        g++;
        ans--;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
