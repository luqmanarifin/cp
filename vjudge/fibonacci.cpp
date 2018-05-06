
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int mod = 1e8 + 7;

long long a[N];

int main() {
  a[0] = a[1] = 1;
  for (int i = 2; i < N; i++) a[i] = (a[i - 1] + a[i - 2]) % mod;
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", a[n-1]);
  }
  return 0;
}
