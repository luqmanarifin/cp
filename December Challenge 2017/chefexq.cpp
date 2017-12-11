#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
const int MAGIC = 320;
 
int a[N], s[N];
vector<int> all[MAGIC];
int lazy[MAGIC];
 
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] ^ a[i];
  for (int i = 1; i <= n; i++) {
    all[i / MAGIC].push_back(s[i]);
  }
  for (int i = 0; i < MAGIC; i++) sort(all[i].begin(), all[i].end());
  while (q--) {
    int t, at, v;
    scanf("%d %d %d", &t, &at, &v);
    int block = at / MAGIC;
    int st = block * MAGIC;
    int to = min(n, (block + 1) * MAGIC - 1);
    if (t == 1) {
      int be = v;
      v ^= a[at];
      a[at] = be;
      
      all[block].clear();
      for (int i = st; i <= to; i++) {
        s[i] ^= lazy[block];
      }
      lazy[block] = 0;
      for (int i = at; i <= to; i++) {
        s[i] ^= v;
      }
      for (int i = st; i <= to; i++) {
        all[block].push_back(s[i]); 
      }
      sort(all[block].begin(), all[block].end());
      
      for (int i = block + 1; i < MAGIC; i++) lazy[i] ^= v;
      
    } else {
      all[block].clear();
      for (int i = st; i <= to; i++) {
        s[i] ^= lazy[block];
        all[block].push_back(s[i]);
      }
      lazy[block] = 0;
      sort(all[block].begin(), all[block].end());
      
      int ans = 0;
      for (int i = st; i <= at; i++) ans += (v == s[i]);
      for (int i = 0; i < block; i++) {
        ans += upper_bound(all[i].begin(), all[i].end(), v ^ lazy[i]) - lower_bound(all[i].begin(), all[i].end(), v ^ lazy[i]);
      }
      printf("%d\n", ans);
    }
  }
 
  return 0;
}
 