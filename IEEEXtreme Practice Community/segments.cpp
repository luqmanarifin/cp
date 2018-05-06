
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int x[N], y[N], n; 

long long solve(int mid) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] <= mid && mid <= y[i]) continue;
    ret += min(abs(mid - x[i]), abs(mid - y[i]));
  } 
  return ret;
} 

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
  int l = -1e9, r = 1e9;
  long long ans = 1e18;
  while (r - l > 3) {
    int lf = (l + l + r) / 3;
    int rf = (r + r + l) / 3;
    long long retl = solve(lf);
    long long retr = solve(rf);
    if (retl < retr) {
      r = rf;
      ans = min(ans, retl);
    } else {
      l = lf;
      ans = min(ans, retr);
    }
  }
  for (int i = l; i <= r; i++) ans = min(ans, solve(i));
  cout << ans << endl;
  return 0;
}
