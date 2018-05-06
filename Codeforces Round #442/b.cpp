
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N];
int cnt[N][2];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    cnt[i][s[i] - 'a']++;
    cnt[i][0] += cnt[i-1][0];
    cnt[i][1] += cnt[i-1][1];
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int cur = cnt[i][0] + (cnt[j][1] - cnt[i][1]) + (cnt[n][0] - cnt[j][0]);
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}
