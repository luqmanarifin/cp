#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

bool is(char c) {
  return c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 1e9;
    for (char goal = 'A'; goal <= 'Z'; goal++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == goal) continue;
        if (is(goal) == is(s[i])) {
          cur += 2;
        } else {
          cur++;
        }
      }
      ans = min(ans, cur);
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
