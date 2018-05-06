
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int BIT = 10;

int ret[BIT][2];
char s[N];
int v[N];

int ans[10], t[10];
int bit[10];

int power(int a, int b) {
  int ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf(" %c %d", &s[i], &v[i]);
  for (int j = 0; j < BIT; j++) {
    for (int k = 0; k < 2; k++) {
      int now = (k << j);
      for (int i = 0; i < n; i++) {
        if (s[i] == '|') {
          now |= v[i];
        } else if (s[i] == '^') {
          now ^= v[i];
        } else {
          now &= v[i]; 
        }
      }
      now &= (1 << j);
      if (now) ret[j][k] = 1;
    }
  }
  // type ^ | &
  for (int len = 1; len <= 5; len++) {
    int to = power(3, len);
    for (int h = 0; h < to; h++) {
      int tmp = h;
      for (int i = 0; i < len; i++) {
        t[i] = tmp % 3;
        tmp /= 3;
      }
      memset(ans, 0, sizeof(ans));
      bool can = 1;
      for (int j = 0; j < BIT; j++) {
        int brute = power(2, len);
        bool found = 0;
        for (int v = 0; v < brute; v++) {
          tmp = v;
          for (int i = 0; i < len; i++) {
            bit[i] = tmp % 2;
            tmp /= 2;
          }
          int zero = 0, one = 1;
          for (int i = 0; i < len; i++) {
            if (t[i] == 0) {
              zero ^= bit[i];
              one ^= bit[i];
            } else if (t[i] == 1) {
              zero |= bit[i];
              one |= bit[i];
            } else {
              zero &= bit[i];
              one &= bit[i];
            }
          }
          if (zero == ret[j][0] && one == ret[j][1]) {
            found = 1;
            break;
          }
        }
        if (found) {
          for (int i = 0; i < len; i++) {
            ans[i] |= (bit[i] << j);
          }
        } else {
          can = 0;
          break;
        }
      }
      if (can) {
        printf("%d\n", len);
        for (int i = 0; i < len; i++) {
          printf("%c %d\n", (t[i] == 0? '^' : (t[i] == 1? '|' : '&')), ans[i]);
        }
        return 0;
      }
    }
  }
  assert(0);
  return 0;
}
