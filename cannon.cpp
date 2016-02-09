#include <bits/stdc++.h>

using namespace std;

int main() {
  int cp, tp, cbs, ws;
  char wd;
  scanf("%d %d %d %d %c", &cp, &tp, &cbs, &ws, &wd);
  int d = (cp <= tp? 1 : -1);
  int v = cbs;
  if(d == 1 && wd == 'R') {
    v += ws;
  } else if(d == 1 && wd == 'L') {
    v -= ws;
  } else if(d == -1 && wd == 'R') {
    v -= ws;
  } else {
    v += ws;
  }
  if(cp == tp) {
    puts("0");
    return 0;
  }
  if(v <= 0) {
    puts("Impossible");
  } else {
    printf("%.15f\n", (double) abs(cp - tp) / v);
  }
  return 0;
}
