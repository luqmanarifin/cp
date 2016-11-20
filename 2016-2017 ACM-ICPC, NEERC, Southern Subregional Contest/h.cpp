#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int a[N];
bool ok[N];
char ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
    a[i]--;
    ok[a[i]] = 1;
  }
  int len = strlen(s[a[0]]);
  for (int i = 0; i < m; i++) {
    if (strlen(s[a[i]]) != len) {
      puts("No");
      return 0;
    }
    for (int j = 0; j < len; j++) {
      ans[j] = s[a[i]][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < len; j++) {
      if (s[a[i]][j] != ans[j]) {
        ans[j] = '?';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ok[i]) continue;
    if (strlen(s[i]) != len) continue;
    bool same = 1;
    for (int j = 0; j < len; j++) {
      if (ans[j] != '?' && ans[j] != s[i][j]) {
        same = 0;
      }
    }
    if (same) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  printf("%s\n", ans);
  return 0;
}
