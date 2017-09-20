#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((a[i] + a[j]) % 2) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
