#include <bits/stdc++.h>

/**
 * Hayo mau liat apa
 * Asu kon
 */

using namespace std;

int ans[25][25][25];

bool get(int x, int r, int c) {
  assert(r <= c);
  if(r * c % x) return 0;
  switch(x) {
    case 1 : return 1; break;
    case 2 : return 1; break;
    case 3 : if(r > 1) return 1; break;
    case 4 :
      if(r == 1) {
        return 0;
      } else if(r == 2) {
        return 0;
      } else if(r == 3) {
        return 1;
      } else {
        return 1;
      }
      break;
    case 5 :
      if(r == 1) {
        return 0;
      } else if(r == 2) {
        return 0;
      } else if(r == 3) {
        if(c > 5) return 1;
      } else {
        return 1;
      }
      break;
    case 6 :
      if(r == 1) {
        return 0;
      } else if(r == 2) {
        return 0;
      } else if(r == 3) {
        return 0;
      } else {
        return 1;
      }
      break;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int x, r, c;
    scanf("%d %d %d", &x, &r, &c);
    if(r > c) swap(r, c);
    printf("Case #%d: ", tt);
    puts(get(x, r, c)? "GABRIEL" : "RICHARD");
  }
  
  return 0;
}
