#include <bits/stdc++.h>

using namespace std;

char s[55][55];
char t[] = "face";

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i + 1 < n; i++) {
    for(int j = 0; j + 1 < m; j++) {
      int cnt[50];
      memset(cnt, 0, sizeof(cnt));
      cnt[s[i][j] - 'a']++;
      cnt[s[i][j+1] - 'a']++;
      cnt[s[i+1][j] - 'a']++;
      cnt[s[i+1][j+1] - 'a']++;
      bool good = 1;
      for(int k = 0; k < 4; k++) {
        if(cnt[t[k] - 'a'] != 1) {
          good = 0;
          break;
        }
      }
      if(good) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
