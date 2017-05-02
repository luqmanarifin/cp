#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char junk[15], s[N];
int one[N], three[N];
int n;

int main() {
  int n;
  scanf("%s %d %s", junk, &n, s + 1);
  for (int i = 1; i <= n; i++) one[i] = one[i-1] + (s[i] == '1');
  for (int i = n; i >= 1; i--) three[i] = three[i + 1] + (s[i] == '3');
  long long ans = 0;
  for (int i = 1; i <= n; i++) if (s[i] == '2') {
    ans += 1LL * one[i-1] * three[i+1];
  }
  cout << ans << endl;
  return 0;
}
