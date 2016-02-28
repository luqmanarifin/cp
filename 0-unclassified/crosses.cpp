#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c, int d) {
  return a * b + c * d - min(a, c) * min(b, d);
}

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  int n2 = n >> 1;
  int m2 = m >> 1;
  long long ans = 0;
  for(int i = 0; i <= n2; i++) {
    for(int j = 0; j <= m2; j++) {
      for(int k = 0; k <= n2; k++) {
        int l = 0, r = m2;
        while(l < r) {
          int mid = (l + r) >> 1;
          if(solve(2*i + 1, 2*j + 1, 2*k + 1, 2*mid + 1) < s) {
            l = mid + 1;
          } else {
            r = mid;
          }
        }
        int low = l;
        
        l = 0, r = m2 + 1;
        while(l < r) {
          int mid = (l + r) >> 1;
          if(solve(2*i + 1, 2*j + 1, 2*k + 1, 2*mid + 1) <= s) {
            l = mid + 1;
          } else {
            r = mid;
          }
        }
        int hig = l;
        
        if(solve(2*i + 1, 2*j + 1, 2*k + 1, 2*low + 1) == s) {
          int x = max(i, k);
          int y = max(j, low);
          if(1 + x <= n - x && 1 + y <= m - y) {
            ans += (hig - low)*(n - 2*x)*(m - 2*y);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}