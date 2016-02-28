#include <bits/stdc++.h>

using namespace std;

int main() {
  long long l, r;
  scanf("%I64d %I64d", &l, &r);
  int ans = 0;
  for(int n = 2; n <= 62; n++) {
    long long all = (1LL << n) - 1;
    for(int i = 0; i < n - 1; i++) {
      long long now = all ^ (1LL << i);
      if(l <= now && now <= r) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
