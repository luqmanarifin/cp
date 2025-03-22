#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d %s", &n, &k, s);
    bool same = 1, diff = 0;
    int need = 1;
    for (int i = 0; i < n; i++) {
      if (i > 0 && s[i] != s[i-1]) {
        same = 0;
      }
      if (!diff && s[i] != s[n-1-i]) {
        diff = 1;
        if (s[i] < s[n-1-i]) {
          need = 0;
        } else {
          need = 1;
        }
      } 
    }
    if (same) {
      puts("NO");
    } else {
      puts(k >= need? "YES" : "NO");
    }
  }

  return 0;
}
