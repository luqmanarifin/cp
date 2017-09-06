#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int K = k, ans = 0;
  if (k <= n / 3) {
    ans = 2 * k;
  } else {
    int block = n / 3;
    int sisa = n - block * 3;
    k -= block;
    k -= sisa;
    ans = 2 * block - k;
  }
  if (K == 0 || K == n) {
    printf("0 ");
  } else {
    printf("1 ");
  }
  cout << ans << endl;
  return 0;
}