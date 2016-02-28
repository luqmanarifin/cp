#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  cout << a[n - k] << endl;
  return 0;
}
