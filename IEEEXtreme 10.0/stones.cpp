#include <bits/stdc++.h>

using namespace std;

int nim[105];

int main() {
  for (int n = 3; n <= 100; n += 2) {
    set<int> s;
    for (int i = 1; i < n; i += 2) {
      for (int j = i; i + j < n; j += 2) {
        int k = n - i - j;
        s.insert(nim[i] ^ nim[j] ^ nim[k]);
      }
    }
    for (int i = 0; i < 1005; i++) {
      if (!s.count(i)) {
        nim[n] = i;
        printf("%d: %d\n", n, i);
        break;
      }
    }
  }

  return 0;
}
