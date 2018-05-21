#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char s[N][N];
int cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        cnt[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1' && cnt[j] == 1) {
        ok = 0;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
