#include <bits/stdc++.h>

using namespace std;

char s[10][5];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < 10; i++) {
      scanf("%s", s[i]);
    }
    bool found = 0;
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        if(i == j) continue;
        for(int p = 0; p < 4; p++) {
          //printf("%d %d %d\n", i, j, p);
          bool good = 1;
          for(int k = 0; k < 4 - p; k++) {
            if(s[i][p + k] != s[j][k]) {
              good = 0;
              break;
            }
          }
          if(i == 0 && j == 5 && p == 3) {
            cerr << "why not good " << good << endl;
          }
          if(good) {
            printf("%s", s[i]);
            for(int k = 4 - p; k < 4; k++) {
              printf("%c", s[j][k]);
            }
            for(int k = 0; k < 10; k++) {
              if(k != i & k != j) {
                printf("%s", s[k]);
              }
            }
            int sisa = 3 - p;
            while(sisa--) printf("A");
            printf("\n");
            found = 1;
            goto CONTINUE;
          }
        }
      }
    }
    CONTINUE:;
    assert(found);
    cerr << tt << " found" << endl;
  }

  return 0;
}
