#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long k;
    scanf("%d %I64d", &n, &k);
    long long mod = (1LL << n);
    k %= mod;
    //cout << k << endl;
    if (k == mod - 1) {
      puts("ON");
    } else {
      puts("OFF");
    }
  }

  return 0;
}
