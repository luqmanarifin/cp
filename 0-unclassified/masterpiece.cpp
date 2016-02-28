#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[105];
int cnt[26];
int a[N];

int get(long long c) {
  int ret = 0;
  for(int i = 0; i < 63; i++) {
    if(c & (1LL << i)) {
      ret += a[i];
    }
  }
  return ret;
}

int main() {
  scanf("%s", s);
  int len = strlen(s);
  for(int i = 0; i < len; i++) {
    cnt[s[i] - 'a']++;
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  while(m--) {
    long long l, r;
    char c;
    scanf("%I64d %I64d %c", &l, &r, &c);
    l--;
    long long bl = l / len;
    long long br = r / len;
    if(bl == br) {
      l %= len;
      r %= len;
      int ans = 0;
      int sl = get(bl);
      for(int i = l; i < r; i++) {
        int at = (i - sl) % len;
        at = (at + len) % len;
        if(s[at] == c) {
          ans++;
        }
      }
      printf("%d\n", ans);
      continue;
    }
    long long cl = l, cr = r;
    while(cl % len) cl++;
    while(cr % len) cr--;
    long long ans = 1LL * (cr - cl) / len * cnt[c - 'a'];
    int sl = get(bl);
    int sr = get(br);
    l %= len;
    r %= len;
    if(l) {
      for(int i = l; i < len; i++) {
        int at = (i - sl) % len;
        at = (at + len) % len;
        if(s[at] == c) {
          ans++;
        }
      }
    }
    for(int i = 0; i < r; i++) {
      int at = (i - sr) % len;
      at = (at + len) % len;
      if(s[at] == c) {
        ans++;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
