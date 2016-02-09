#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[26];
char s[N];

int main() {
  int n;
  int ans = 0;
  scanf("%d %s", &n, s);
  for(int i = 0; s[i]; i++) {
    cnt[s[i++] - 'a']++;
    if(cnt[s[i] - 'A']) {
      cnt[s[i] - 'A']--;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
