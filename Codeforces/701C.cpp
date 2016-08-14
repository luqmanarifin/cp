#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[256], ada[256];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) {
    ada[s[i]] = 1;
  }
  int all = 0;
  for (int i = 0; i < 256; i++) if (ada[i]) all++;
  
  int r = 0;
  int ans = 1e9;
  
  int now = 1;
  cnt[s[0]]++;
  for (int i = 0; i < n; i++) {
    if (r < i) {
      r = i;
      now++;
      cnt[s[i]]++;
    }
    while (now < all && r + 1 < n) {
      r++;
      if (cnt[s[r]] == 0) now++;
      cnt[s[r]]++;
    }
    if (now == all) {
      ans = min(ans, r - i + 1);
    }
    if (cnt[s[i]] == 1) now--;
    cnt[s[i]]--;
  }
  cout << ans << endl;
  return 0;
}
