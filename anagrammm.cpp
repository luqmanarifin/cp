#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], t[N];
int cnt[26];
int must[26];

int main() {
  scanf("%s %s", s, t);
  int len = strlen(s);
  int tlen = strlen(t);
  for(int i = 0; i < tlen; i++) {
    must[t[i] - 'a']++;
    if(s[i] != '?' && i < len) cnt[s[i] - 'a']++;
  }
  int ans = 0;
  for(int i = 0; i + tlen <= len; i++) {
    bool good = 1;
    for(int j = 0; j < 26; j++) {
      if(cnt[j] > must[j]) {
        good = 0;
        break;
      }
    }
    ans += good;
    if(s[i] != '?') cnt[s[i] - 'a']--;
    if(i + tlen < len && s[i + tlen] != '?') cnt[s[i + tlen] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}
