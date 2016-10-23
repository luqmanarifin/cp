#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char ori[N], s[N], a[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) ori[i] = s[i];
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, k;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      scanf("%d", &k);
      bool same = 1;
      int len = r - l + 1;
      for (int i = 0; i < len; i++) {
        if (s[l + i] != s[k + i]) {
          same = 0;
          break;
        }
      }
      puts(same? "Y" : "N");
    } else if (t == 2) {
      scanf("%d", &k);
      int len = r - l + 1;
      for (int i = 0; i < len; i++) s[l + i] = ori[k + i];
    } else {
      for (int i = l; i <= r; i++) {
        if (s[i] == 'z') s[i] = 'a';
        else s[i]++;
      }
    }
  }

  return 0;
}
