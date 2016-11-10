#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool ans[1 << 7];
int num[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

char s[N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ans, 0, sizeof(ans));
    
    int n;
    scanf("%d", &n);
    int on = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      a[i] = 0;
      for (int j = 0; j < len; j++) {
        if (s[j] == '1') {
          a[i] += (1 << j);
        }
      }
      on |= a[i];
    }
    for (int mask = on; mask < (1 << 7); mask = ((mask + 1) | on)) {
      for (int start = 0; start < 10; start++) {
        bool can = 1;
        for (int i = 0; i < n; i++) {
          int must = (mask & num[((start - i) % 10 + 10) % 10]);
          if (a[i] != must) {
            can = 0;
            break;
          }
        }
        if (can) {
          int must = (mask & num[((start - n) % 10 + 10) % 10]);
          ans[must] = 1;
        }
      }
    }
    int ada = 0, p = -1;
    for (int i = 0; i < (1 << 7); i++) {
      if (ans[i]) {
        ada++;
        p = i;
      }
    }
    //cout << ada << endl;
    if (ada == 1) {
      for (int i = 0; i < 7; i++) {
        if (p & (1 << i)) {
          printf("1");
        } else {
          printf("0");
        }
      }
      printf("\n");
    } else {
      puts("ERROR!");
    }
  }

  return 0;
}
