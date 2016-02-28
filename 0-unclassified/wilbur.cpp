#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 +5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long now = 0;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ans += abs(a[i] - now);
    now = a[i];
  }
  cout << ans << endl;
  return 0;
}
