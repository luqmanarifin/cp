#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

void print(int x) {
  for (int i = 9; i >= 0; i--) {
    if (x & (1 << i)) {
      printf("-");
    } else {
      printf(".");
    }
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %s", &n, s);
    int seed = (s[0] == '.'? (1 << 9) : 0);
    printf("Case #%d:\n", tt);
    for (int i = 0; i < n - 1; i++) {
      print(seed + i);
    }
  }
  return 0;
}
