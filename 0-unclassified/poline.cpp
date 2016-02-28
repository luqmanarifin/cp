#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int j = upper_bound(a, a + n, a[i] + d) - a - 1;
    long long dif = j - i;
    ans += dif*(dif - 1)/2;
  }
  cout << ans << endl;
  return 0;
}