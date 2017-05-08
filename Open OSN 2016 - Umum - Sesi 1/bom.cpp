#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  int bip = 0;
  
  int n, t, type;
  scanf("%s %d %d %d", s, &n, &t, &type);
  int l = 1, r = n;
  while(l < r) {
    int mid = (l + r) >> 1;
    bool done = 0;
    for(int i = mid + 1; i <= r; i++) {
      printf("%d\n", i);
      fflush(stdout);
      scanf("%s", s);
      if(s[0] == 'B') {
        bip++;
        done = 1;
        break;
      }
    }
    if (bip == n) return 0;
    if(!done) {
      for(int i = 1; i < n; i++) {
        printf("%d\n", r);
        fflush(stdout);
        scanf("%s", s);
        if(s[0] == 'B') {
          bip++;
          done = 1;
          break;
        }
      }
      if (bip == n) break;
    }
    if(done) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  while(bip < n) {
    printf("%d\n", l);
    fflush(stdout);
    scanf("%s", s);
    if(s[0] == 'B') {
      bip++;
    }
  }
  return 0;
}