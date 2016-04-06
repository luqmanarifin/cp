#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

long long a[2][N];
long long b[2][N];
bool done[2][N];

int main() {
  int n, r, k;
  int tt = 0;
  scanf("%d %d %d", &n, &r, &k);
  while(n && r && k) {
    memset(done, 0, sizeof(done));
    tt++;
    r--; k--;
    long long mn = 1e18, sum = 0;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%I64d", &a[i][j]);
        mn = min(mn, a[i][j]);
        sum += a[i][j];
      }
    }
    printf("Case %d:\n", tt);
    int ro = r, ko = k;
    while(1) {
      if(a[r][k] == mn) {
        if(r == 0) {
          puts("INVALID");
        } else {
          long long del = a[r][k];
          if(ro == r && ko == k) {
            for(int i = 0; i < 2; i++) {
              for(int j = 0; j < n; j++) {
                printf("%I64d ", a[i][j] - del + (i == r && j == k? del * n * 2 : 0));
              }
              printf("\n");
            }
          } else {
            for(int i = 0; i < 2; i++) {
              for(int j = 0; j < n; j++) {
                b[i][j] = a[i][j];
              }
            }
            int sr = r, sk = k;
            while(1) {
              if(r == 0) {
                if(k) {
                  k--;
                } else {
                  r++;
                }
              } else {
                if(k + 1 < n) {
                  k++;
                } else {
                  r--;
                }
              }
              done[r][k] = 1;
              b[r][k] -= del + 1;
              if(r == ro && k == ko) break;
            }
            long long tsum = 0;
            for(int i = 0; i < 2; i++) {
              for(int j = 0; j < n; j++) {
                if(!done[i][j]) {
                  b[i][j] -= del;
                }
                tsum += b[i][j];
              }
            }
            b[sr][sk] += sum - tsum;
            
            for(int i = 0; i < 2; i++) {
              for(int j = 0; j < n; j++) {
                printf("%I64d ", b[i][j]);
              }
              printf("\n");
            }
          }
        }
        break;
      }
      if(r == 0) {
        if(k + 1 < n) {
          k++;
        } else {
          r++;
        }
      } else {
        if(k) {
          k--;
        } else {
          r--;
        }
      }
    }
    scanf("%d %d %d", &n, &r, &k);
  }
  
  return 0;
}