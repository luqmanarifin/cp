#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int sum[N][2];
char s[N];

int find(int l, int r, int c) {
  return sum[r][c] - sum[l-1][c];
}

void clear(int n) {
  for (int i = 1; i <= n; i++) {
    sum[i][0] = sum[i][1] = 0;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
      sum[i][0] += sum[i-1][0];
      sum[i][1] += sum[i-1][1];
      if (s[i] == '[' || s[i] == ']') {
        sum[i][i % 2]++;
      }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int ev = find(l, r, 0);
      int od = find(l, r, 1);
      int tot = ev + od;
      printf("%d\n", tot - 2 * min(ev, od));
    }

    clear(n);
  }

  return 0;
}
