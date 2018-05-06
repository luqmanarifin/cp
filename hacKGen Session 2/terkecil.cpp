
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int last[N][26];
char s[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), m;
  memset(last, -1, sizeof(last));
  scanf("%d", &m);
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      last[i][j] = last[i + 1][j];
    }
    if (i + 1 <= n) {
      last[i][s[i + 1] - 'a'] = i + 1;
    }
  }
  int now = 0;
  for (int need = m; need >= 1; need--) {
    for (int i = 0; i < 26; i++) {
      if (last[now][i] == -1) continue;
      if (n - last[now][i] + 1 >= need) {
        now = last[now][i];
        printf("%c", i + 'a');
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
