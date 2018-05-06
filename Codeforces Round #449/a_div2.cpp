
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s + 1);
  while (m--) {
    int l, r;
    char a, b;
    scanf("%d %d %c %c", &l, &r, &a, &b);
    for (int i = l; i <= r; i++) if (s[i] == a) s[i] = b;
  }
  printf("%s\n", s + 1);
  return 0;
}
