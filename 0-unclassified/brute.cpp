#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int s[N][N];
int a[N * N], b[N * N];

int main() {
  for(int n = 3; n <= 7; n++) {
    int pt = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
        a[pt] = i;
        b[pt] = j;
        pt++;
      }
    }
    for(int mask = 0; mask < (1 << pt); mask++) {
      memset(s, 0, sizeof(s));
      bool ada = 0;
      for(int i = 0; i < pt; i++) {
        if(mask & (1 << i)) {
          s[a[i]][b[i]] = 1;
        }
      }
      for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
          for(int k = j + 1; k <= n; k++) {
            if(s[i][j] == s[j][k] && s[j][k] == s[i][k]) {
              ada = 1;
              goto WOW;
            }
          }
        }
      }
      WOW:;
      if(!ada) {
        printf("%d ada yang ngeblok\n", n);
        break;
      }
    }
  }
  
  return 0;
}