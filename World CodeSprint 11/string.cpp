#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int main() {
  int k, b, m;
  scanf("%s %d %d %d", s, &k, &b, &m);
  int n = strlen(s);
  int trans = 1 % m;
  for (int i = 0; i < k; i++) trans = trans * b % m;
  int now = 0;
  for (int i = 0; i < k; i++) now = (now * b + s[i] - '0') % m;
  long long ans = now;
  for (int i = k; i < n; i++) {
    now = (now * b + s[i] - '0') % m;
    now -= (s[i-k] - '0') * trans;
    now %= m;
    if (now < 0) now += m;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
