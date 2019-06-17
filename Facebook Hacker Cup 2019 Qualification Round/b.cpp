#include <bits/stdc++.h>

using namespace std;

bool ok(int n, int beta) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return beta == 1;
  } else {
    if (n == beta) return 0;
    int need = 2 + (n - 3) / 2;
    if (beta >= need) return 1;
    if (beta >= 2) return 1;
    return 0;
  }
}

const int N = 5005;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    int beta = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        beta++;
      }
    }
    bool ans = ok(n - 1, beta);
    printf("Case #%d: %c\n", tt, ans? 'Y' : 'N');
  }
  return 0;
}
