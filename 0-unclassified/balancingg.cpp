#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  sort(a, a + n);
  int b = sum / n;
  int c = sum % n;
  int ans = 0;
  for(int i = 0; i < n - c; i++) {
    ans += abs(b - a[i]);
  }
  for(int i = n - c; i < n; i++) {
    ans += abs(b + 1 - a[i]);
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}
