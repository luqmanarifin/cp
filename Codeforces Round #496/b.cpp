#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N], t[N];

int main() {
  scanf("%s %s", s, t);
  int ns = strlen(s);
  int nt = strlen(t);
  int ans = 0;
  for (int i = 1; i <= ns && i <= nt; i++) {
    if (s[ns - i] == t[nt - i]) {
      ans = i;
    } else {
      break;
    }
  }
  printf("%d\n", ns + nt - 2 * ans);
  return 0;
}
