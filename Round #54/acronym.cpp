#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

string s[N];
int cnt[N][26];
int dep[26];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      cnt[i][s[i][j] - 'a']++;
    }
    dep[s[i][0] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dep[s[i][0] - 'a']--;
    
    bool ok = 1;
    for (int j = 0; j < 26; j++) {
      if (cnt[i][j] > dep[j]) {
        ok = 0;
      }
    }
    if (ok) ans++;
    
    dep[s[i][0] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}
