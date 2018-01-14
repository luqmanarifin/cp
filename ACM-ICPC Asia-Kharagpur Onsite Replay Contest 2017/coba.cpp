#include <bits/stdc++.h>

using namespace std;

int a[20];

int main() {
  for (int n = 2; n <= 10; n++) {
    set<int> s;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
      int cur = 0;
      for (int i = 1; i < n; i++) cur += max(a[i-1], a[i]);
      s.insert(cur);
    } while (next_permutation(a, a + n));
    printf("%d: ", n);
    for (auto it : s) printf("%d ", it); printf("\n");
  }

  return 0;
}
