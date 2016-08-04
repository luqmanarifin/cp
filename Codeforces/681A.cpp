#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%s %d %d", s, &a, &b);
    if (a >= 2400 && a < b) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
