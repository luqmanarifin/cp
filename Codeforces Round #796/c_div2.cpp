#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[26];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));

    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n + 1; i++) {
      scanf("%s", s);
      int len = strlen(s);
      for (int j = 0; j < len; j++) {
        cnt[s[j] - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2) {
        printf("%c\n", i + 'a');
        break;
      }
    }
  }

  return 0;
}
