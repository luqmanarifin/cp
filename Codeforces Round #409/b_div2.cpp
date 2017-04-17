#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char x[N], y[N];

int main() {
  scanf("%s %s", x, y);
  int n = strlen(x);
  for (int i = 0; i < n; i++) {
    if (y[i] > x[i]) {
      puts("-1");
      return 0;
    }
  }
  printf("%s\n", y);
  return 0;
}