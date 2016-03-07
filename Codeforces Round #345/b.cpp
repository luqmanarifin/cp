#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N];

int main() {
  int n, a, b, t;
  scanf("%d %d %d %d %s", &n, &a, &b, &t, s);
  if(s[0] == 'w' && t < b + 1) {
    puts("0");
    return 0;
  }
  if(s[0] == 'w') {
    t -= b + 1;
  } else {
    t--;
  }
  vector<long long> up, down;
  s[n] = s[0];
  long long now = 0;
  for(int i = 1; i < n; i++) {
    if(s[i] != 'h') {
      now += a + b + 1;
    } else {
      now += a + 1;
    }
    up.push_back(now);
  }
  now = 0;
  for(int i = n - 1; i >= 1; i--) {
    if(s[i] != 'h') {
      now += a + b + 1;
    } else {
      now += a + 1;
    }
    down.push_back(now);
  }
  assert(up.size() == down.size());
  int ans = 1;
  for(int i = 0; i < up.size(); i++) {
    if(up[i] <= t) {
      int j = upper_bound(down.begin(), down.end(), t - up[i] - 1LL*(i+1)*a) - down.begin();
      ans = max(ans, 2 + i + j);
    }
    if(down[i] <= t) {
      int j = upper_bound(up.begin(), up.end(), t - down[i] - 1LL*(i+1)*a) - up.begin();
      ans = max(ans, 2 + i + j);
    }
  }
  cout << min(n, ans) << endl;
  return 0;
}
