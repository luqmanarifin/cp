#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int sm = 0, bi = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '<') {
        sm++;
      } else {
        bi++;
      }
    }  
    printf("%d", sm + 1);
    int sm_now = sm;
    int bg_now = n - bi + 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '<') {
        printf(" %d", sm_now--);
      } else {
        printf(" %d", bg_now++);
      }
    }
    printf("\n");
  }

  return 0;
}
