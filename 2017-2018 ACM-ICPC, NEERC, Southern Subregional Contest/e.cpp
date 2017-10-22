#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N], p[N];
bool ok[N], tutup[N], buka[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < N; i++)
    ok[i] = 1;
  for (int i = 0; i < m; i++) {
    scanf("%s", p);
    memset(buka, 0, sizeof buka);
    memset(tutup, 0, sizeof tutup);
    bool can = 1;
    for (int j = 0; j < n; j++) if (s[j] == '*') {
      tutup[p[j]-'a'] = 1;
    }
    else {
      buka[p[j]-'a'] = 1;
      can &= p[j] == s[j];
    }
    for (int j = 0; j < 26; j++) if (buka[j] & tutup[j])
      can = 0;
    if (!can) continue;
    for (int j = 0; j < 26; j++)
      ok[j] &= tutup[j];
  }
  int ans = 0;
  for (int j = 0; j < 26; j++)
    ans += ok[j];
  printf("%d\n", ans);
  return 0;
}
