#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  
  long long ans = a[0] - 1;
  long long price = 2;
  for (int i = 1; i < n; i++) {
    if (a[i] > price) {
      ans += (a[i] - 1) / price;
    } else {
      price = max(price, 1LL * a[i] + 1);
    }
  }
  cout << ans << endl;
  return 0;
}