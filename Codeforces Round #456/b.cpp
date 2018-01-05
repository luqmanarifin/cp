#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  scanf("%I64d %I64d", &n, &k);
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  int big = -1;
  for (int i = 62; i >= 0; i--) {
    if (n & (1LL << i)) {
      big = i;
      break;
    }
  }
  cout << (1LL<<(big+1))-1 << endl;

  return 0;
}
