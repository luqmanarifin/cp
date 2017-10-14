#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long tot = 0, mini = 1e18, maxi = -1e18;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += a[i];
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  set<long long> s;
  s.insert(tot);
  s.insert(mini);
  s.insert(maxi);
  for (int i = 0; ; i++) if (!s.count(i)) {
    cout << i << endl;
    return 0;
  }

  return 0;
}
