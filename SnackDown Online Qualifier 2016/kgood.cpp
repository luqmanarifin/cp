#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[26];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(cnt, 0, sizeof(cnt));
    
    int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    int p = 1e9;
    for(int i = 0; i < 26; i++) {
      if(cnt[i]) {
        p = min(p, cnt[i]);
      }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
      if(cnt[i] > p + k) {
        ans += cnt[i] - p - k;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}