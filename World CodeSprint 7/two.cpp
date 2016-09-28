#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];
vector<int> at[30];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) {
    at[s[i] - 'a'].push_back(i);
  }
  int ans = 0;
  for (int p = 0; p < 26; p++) {
    for (int q = 0; q < 26; q++) {
      if (p == q) continue;
      int cp = at[p].size();
      int cq = at[q].size();
      if (cp != cq && cq + 1 != cp) continue;
      bool valid = 1;
      for (int i = 0; i < cq; i++) {
        valid &= at[p][i] < at[q][i];
        if (i) {
          valid &= at[q][i - 1] < at[p][i];
        }
      }
      if (cq + 1 == cp && cq != 0) {
        valid &= at[q].back() < at[p].back();
      }
      if (valid) {
        ans = max(ans, cp + cq);
      }
    }
  }
  if (ans == 1) ans = 0;
  printf("%d\n", ans);
  return 0;
}