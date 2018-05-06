
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];
int can[N][N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      can[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int now = 0, ask = 0;
    for (int j = i; j <= n; j++) {
      if (s[j] == '(') {
        now++;
      } else if (s[j] == ')') {
        now--;
      } else {
        ask++;
      }
      if (now < 0) {
        if (ask == 0) {
          for (int k = j; k <= n; k++) {
            can[i][k] = 0;
          }
          break;
        } else {
          ask--;
          now++;
        }
      }
      if ((j - i) % 2 == 0 || ask < now) {
        can[i][j] = 0;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    int now = 0, ask = 0;
    for (int j = i; j >= 1; j--) {
      if (s[j] == '(') {
        now--;
      } else if (s[j] == ')') {
        now++;
      } else {
        ask++;
      }
      if (now < 0) {
        //printf("minus %d %d\n", j, i);
        if (ask == 0) {
          for (int k = j; k >= 1; k--) {
            can[k][i] = 0;
          }
          break;
        } else {
          ask--;
          now++;
        }
      }
      if ((i - j) % 2 == 0 || ask < now) {
        can[j][i] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (can[i][j]) {
        //printf("%d %d\n", i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
