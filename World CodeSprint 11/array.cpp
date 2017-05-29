#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
  cout << abs(s[n/2] - (s[n] - s[n/2])) << endl;
  return 0;
}
