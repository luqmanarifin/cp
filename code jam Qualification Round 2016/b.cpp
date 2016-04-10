#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    n = unique(s, s + n) - s;
    reverse(s, s + n);
    int ans = 0;
    for(int i = s[0] == '+'; i < n; i++) {
      ans++;
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}