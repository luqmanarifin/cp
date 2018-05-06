
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

// k - n
map<int, int> nim[N];

int find(int k, int n) {
  if (n < k) return 0;
  if (nim[k].count(n)) return nim[k][n];
  set<int> s;
  for (int i = 1; i <= n / k; i++) {
    s.insert(find(k, n - i));
  }
  for (int i = 0; ; i++) {
    if (!s.count(i)) {
      return nim[k][n] = i;
    }
  }
}

int main() {
  for (int k = 1; k <= 10; k++) {
    for (int n = 1; n <= 100; n++) {
      printf("%d %d: %d\n", k, n, find(k, n));
    }
  }

  return 0;
}
