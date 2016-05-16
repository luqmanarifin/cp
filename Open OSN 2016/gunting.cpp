#include <bits/stdc++.h>

using namespace std;

char s[22];

int main() {
  scanf("%s", s);
  int n, m;
  scanf("%d %d", &n, &m);
  while(n != 1 || m != 1) {
    if(n < m) {
      printf("%d %d\n", n, n);
    } else if(n > m) {
      printf("%d %d\n", m, m);
    } else {
      assert(0);
    }
    fflush(stdout);
    int mini = min(n, m);
    if(mini == 1) break;
    scanf("%d %d", &n, &m);
  }
  return 0;
}