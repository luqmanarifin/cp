#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e8;

int main() {
  for (int i = 0; i < mod; i++) {
    long long n = 12000;
    long long now = i * n % mod;
    if (now == n / 3) {
      cout << i << endl;
    }
  }

  return 0;
}
