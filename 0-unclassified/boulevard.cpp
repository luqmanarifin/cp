#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int t[N], s[N], f[N];
int ans[N];

bool terpisah(int a, int b, int c, int d) {
  return b < c || d < a;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d", t + i, s + i, f + i);
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int ta = t[i], sa = s[i], fa = f[i];
      int tb = t[j], sb = s[j], fb = f[j];
      int da = (sa < fa? 1 : -1);
      int db = (sb < fb? 1 : -1);
      
      if(terpisah(min(sa, fa), max(sa, fa), min(sb, fb), max(sb, fb))) continue;
      if(da == -1) {
        swap(ta, tb);
        swap(da, db);
        swap(sa, sb);
        swap(fa, fb);
      }
      int st = max(ta, tb);
      sa += da * (st - ta);
      sb += db * (st - tb);
      if(da == db) {
        if(sa == sb) {
          ans[i]++;
          ans[j]++;
        }
        continue;
      }
      if(fa < sa) continue;
      if(fb > sb) continue;
      int dif = max(0, max(fb - sa, sb - fa));
      sa += dif;
      sb -= dif;
      if(fa < sa) continue;
      if(fb > sb) continue;
      if(sa <= sb) {
        ans[i]++;
        ans[j]++;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
