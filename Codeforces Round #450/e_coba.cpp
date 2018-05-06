
#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int m = 2; m <= 10; m++) {
    long long need = 0;
    int n = 1e5;
    for (int i = 1; i <= n; i++) {
      need += i / m;
    }
    printf("%d: %lld\n", m, need);
  }

  return 0;
}
