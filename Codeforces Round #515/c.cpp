#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int pos[N];

int main() {
  int q;
  scanf("%d", &q);
  int l = N, r = N;
  bool first = 1;
  while (q--) {
    char c; int p;
    scanf(" %c %d", &c, &p);
    // printf("%c %d\n", c, p);
    if (first) {
      pos[p] = l;
      l--; r++;
    } else if (c == 'L') {
      pos[p] = l;
      l--;
    } else if (c == 'R') {
      pos[p] = r;
      r++;
    } else {
      int now = pos[p];
      // printf("%d %d %d\n", l, now, r);
      printf("%d\n", min(now - l, r - now) - 1);
    } 
    first = 0;
  } 
  
  return 0;
}
