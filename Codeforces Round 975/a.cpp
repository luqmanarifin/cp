#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; long long k;
    scanf("%d %lld", &n, &k);
    long long sum = 0, maks = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      sum += a[i];
      maks = max(maks, a[i]);
    }
    long long tot = sum + k;
    bool found = 0;
    for (long long deck = n; deck >= 1; deck--) {
      long long best = tot / deck * deck;
      if (best < sum) continue;
      if (maks <= best / deck) {
        found = 1;
        printf("%lld\n", deck);
        break;
      }
    }
    if (!found) assert(0);
  }
  return 0;
}
