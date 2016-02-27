#include <bits/stdc++.h>

using namespace std;

char s[25][25];
int da[] = {0, 1, 1, 1, -1, -1, -1, 0};
int db[] = {1, 1, 0, -1, 1, 0, -1, -1};
int v[9];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(s[i][j] != '.') continue;
        memset(v, 0, sizeof(v));
        for(int d = 0; d < 8; d++) {
          int a = i + da[d], b = j + db[d];
          while(0 <= a && a < n && 0 <= b && b < n && s[a][b] == 'X') {
            v[d]++;
            a += da[d];
            b += db[d];
          }
        }
        for(int d = 0; d < 4; d++) {
          if(v[d] + v[7 - d] >= k - 1) {
            puts("YES");
            goto YA;
          }
        }
      }
    }
    puts("NO");
    YA:;
  }
  
  return 0;
}
