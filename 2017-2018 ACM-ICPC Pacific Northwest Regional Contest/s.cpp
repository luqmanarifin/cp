#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  set<pair<int, int>> mn, mx;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      now++;
    } else {
      now--;
    }
    mn.insert(make_pair(now, i));
    mx.insert(make_pair(-now, i));
  }
  now = 0;
  tuple<int, int, int> ans = make_tuple(1e9, 1e9, 1e9);
  for (int i = 1; i <= n; i++) {
    {
      auto it = mn.begin();
      if (it->first <= 0) {
        int d = abs(it->first - now);
        ans = min(ans, make_tuple(-d, i, it->second));
      }
    }
    {
      auto it = mx.begin();
      if (it->first <= 0) {
        int d = abs(-it->first - now);
        ans = min(ans, make_tuple(-d, i, it->second));
      }
    }

    if (s[i] == 'B') {
      now++;
    } else {
      now--;
    }
    mn.erase(make_pair(now, i));
    mx.erase(make_pair(-now, i));
  }
  int l, r;
  tie(ignore, l, r) = ans;
  printf("%d %d\n", l, r);
  return 0;
}
