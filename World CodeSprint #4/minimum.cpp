#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = N;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(a[i] == a[j]) {
        ans = min(ans, j - i);
      }
    }
  }
  if(ans == N) ans = -1;
  cout << ans << endl;
  return 0;
}
