
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int s[N], d[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", s + i, d + i);
  int now = 0;
  for (int i = 0; i < n; i++) {
    now = max(now + 1, s[i]);
    while (now % d[i] != s[i] % d[i]) now++;
  }
  cout << now << endl;
  return 0;
}
