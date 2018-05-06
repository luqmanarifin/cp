
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += n * a[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += n * a[i];
  }
  cout << tot << endl;
  return 0;
}
