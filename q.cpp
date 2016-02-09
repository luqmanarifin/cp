#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  long long now = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(now <= a[i]) {
      now += a[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
