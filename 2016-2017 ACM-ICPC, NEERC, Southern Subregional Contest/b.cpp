#include <bits/stdc++.h>

using namespace std;

char c;
int call, limit;
int mini[55][55], maxi[55][55];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    limit = 3*n/2 + 3*n%2 - 2;
    call = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) { 
        mini[i][j] = maxi[i][j] = i;
      }
    }
    int maxj = 0;
    for (int j = 1; (1<<(j-1)) <= n; j++) {
      for (int i = 1; i <= n; i += (1<<j)) {
        //printf("PARAH %d %d\n", i, j);
        int r = i+(1<<(j-1));
        if (r > n) {
          mini[i][j] = mini[i][j-1];
          maxi[i][j] = maxi[i][j-1];
          continue;
        }
        
        maxj = j;
        
        if (j == 1) {
          call++;
          assert(call <= limit);
          printf("? %d %d\n", mini[i][j-1], mini[r][j-1]);
          fflush(stdout);
          scanf(" %c", &c);
          if (c == '<') {
            mini[i][j] = mini[i][j-1];
            maxi[i][j] = mini[r][j-1];
          } else {
            mini[i][j] = mini[r][j-1];
            maxi[i][j] = mini[i][j-1];
          }
          continue;
        }
        
        call++;
        assert(call <= limit);
        printf("? %d %d\n", mini[i][j-1], mini[r][j-1]);
        fflush(stdout);
        scanf(" %c", &c);
        if (c == '<') {
          mini[i][j] = mini[i][j-1];
        } else {
          mini[i][j] = mini[r][j-1];
        }
        
        call++;
        assert(call <= limit);
        printf("? %d %d\n", maxi[i][j-1], maxi[r][j-1]);
        fflush(stdout);
        scanf(" %c", &c);
        if (c == '<') {
          maxi[i][j] = maxi[r][j-1];
        } else {
          maxi[i][j] = maxi[i][j-1];
        }
      }
    }
    printf("! %d %d\n", mini[1][maxj], maxi[1][maxj]);
    fflush(stdout);
  }

  return 0;
}
