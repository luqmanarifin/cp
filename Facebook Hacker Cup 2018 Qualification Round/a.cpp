#include <bits/stdc++.h>

using namespace std;

string s[55];
int ans[55];

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    memset(ans, 0, sizeof(ans));
    long long n, k, v;
    cin >> n >> k >> v;
    for (int i = 0; i < n; i++) cin >> s[i];
    long long base = k * (v - 1);
    printf("Case #%d:", tt);
    for (int i = 0; i < k; i++) {
      ans[(base + i) % n] = 1;
    }
    for (int i = 0; i < n; i++) if (ans[i]) {
      printf(" %s", s[i].c_str());
    }
    printf("\n");
  }

  return 0;
}
