#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int cnt[30];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));

    int n;
    scanf("%d %s", &n, s);
    int biggest = 0, p = -1;
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      cnt[c]++;
      if (cnt[c] > biggest) {
        biggest = cnt[c];
        p = c;
      }
    }
    int ans = max(n % 2, biggest - (n - biggest));
    printf("%d\n", ans);
  }

  return 0;
}
