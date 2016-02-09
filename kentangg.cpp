#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], p[N];

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &p[i]);
    if(i) p[i] = min(p[i], p[i - 1]);
    ans += a[i] * p[i];
  }
  cout << ans << endl;
  return 0;
}
