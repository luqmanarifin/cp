#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, c, d;
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
  int sa = -1e9;
  sa = max(sa, a + b + 2);
  sa = max(sa, a + c + 2);
  sa = max(sa, c + d + 2);
  sa = max(sa, b + d + 2);
  int sb = 1e9;
  sb = min(sb, a + b + 2*n);
  sb = min(sb, a + c + 2*n);
  sb = min(sb, c + d + 2*n);
  sb = min(sb, b + d + 2*n);
  
  long long ans = 0;
  for(int sum = sa; sum <= sb; sum++) {
    int l = 1;
    l = max(l, sum - a - b - n);
    l = max(l, sum - a - c - n);
    l = max(l, sum - c - d - n);
    l = max(l, sum - b - d - n);
    
    int r = n;
    r = min(r, sum - a - b - 1);
    r = min(r, sum - a - c - 1);
    r = min(r, sum - c - d - 1);
    r = min(r, sum - b - d - 1);
    if(l <= r) {
      ans += r - l + 1;
    }
  }
  cout << ans << endl;
  return 0;
}