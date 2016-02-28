#include <bits/stdc++.h>

using namespace std;

int worth[105];
char ans[105][105];
vector<int> num;
int now;

void create(int &n) {
  for(int i = 3; i <= 100; i++) {
    if(worth[i + 1] > n) {
      now = i;
      n -= worth[i];
      int full = i;
      for(int j = 1; j <= full; j++) {
        for(int k = 1; k <= full; k++) {
          if(j != k) ans[j][k] = 1;
        }
      }
      for(int i = full + 1; n; i++) {
        for(int j = 2; j <= full; j++) {
          if(j*(j - 1)/2 > n) {
            for(int k = 1; k < j; k++) {
              ans[k][i] = 1;
              ans[i][k] = 1;
            }
            n -= (j - 1)*(j - 2)/2;
            break;
          }
        }
        now = i;
      }
      return;
    }
  }
}

int main() {
  int k;
  scanf("%d", &k);
  for(int i = 3; i <= 100; i++) {
    worth[i] = 1;
    for(int j = 0; j < 3; j++) {
      worth[i] *= (i - j);
    }
    worth[i] /= 6;
  }
  create(k);
  //printf("%d butuh %d ", kk, now);
  assert(now <= 100); 
  cout << now << endl;
  for(int i = 1; i <= now; i++) {
    for(int j = 1; j <= now; j++) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  //printf("%d done!\n", kk);
  return 0;
}