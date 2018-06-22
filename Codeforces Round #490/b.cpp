#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      // printf("%d\n", i);
      reverse(s + 1, s + 1 + i);
      // printf("%s\n", s + 1);
    }
  }
  printf("%s\n", s + 1);
  return 0;
}
