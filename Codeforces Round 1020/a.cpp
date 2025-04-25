#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        cnt++;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        ans += cnt + 1;
      } else {
        ans += cnt - 1;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
