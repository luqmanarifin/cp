#include <bits/stdc++.h>

using namespace std;

char s[1005];
int a, b, c, d;
int e, f, g, h;

bool fuck(int i, int j) {
  return a <= i && i <= c && b <= j && j <= d;
}

bool cuk(int i, int j) {
  return e <= i && i <= g && f <= j && j <= h;
}

int main() {
  scanf("%s", s);
  scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
  c--; d--; g--; h--;
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if(fuck(i, j) && cuk(i, j)) {
        puts("SENGKETA");
        return 0;
      }
    }
  }
  puts("DAMAI");
  return 0;
}
