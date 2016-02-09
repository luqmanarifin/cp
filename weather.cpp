#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int f[N];
int b[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    f[i] += f[i - 1];
    if(a[i] >= 0) {
      f[i]++;
    }
  }
  for(int i = n; i >= 1; i--) {
    b[i] += b[i + 1];
    if(a[i] <= 0) {
      b[i]++;
    }
  }
  int ans = 1e9;
  for(int i = 1; i < n; i++) {
    ans = min(ans, f[i] + b[i + 1]);
  }
  cout << ans << endl;
  return 0;
}