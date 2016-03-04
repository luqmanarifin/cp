#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long aa = 0, bb = 0;
    for(int j = i; j < n; j++) {
      aa |= a[j];
      bb |= b[j];
      ans = max(ans, aa + bb);
    }
  }
  cout << ans << endl;
  return 0;
}
