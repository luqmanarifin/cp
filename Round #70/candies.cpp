
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

long long a[N], b[N], n;
int k;

long long satu() {
  memset(a, 0, sizeof(a));
  if (k + k / 2 > n) return inf;
  long long sum = 0;
  for (int i = 1; i < k; i += 2) a[i] = 1, sum++;
  long long rem = n - sum;
  long long add = rem / k, pas = rem % k;
  int p = 0;
  for (int i = 1; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  for (int i = 0; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  long long mini = inf, maxi = -inf;
  for (int i = 0; i < k; i++) {
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  return maxi - mini;
}

long long dua() {
  memset(a, 0, sizeof(a));
  long long slot = (k % 2? k / 2 + 1 : k / 2);
  if (k + slot > n) return inf;
  long long sum = 0;
  for (int i = 0; i < k; i += 2) a[i] = 1, sum++;
  long long rem = n - sum;
  long long add = rem / k, pas = rem % k;
  int p = 0;
  for (int i = 0; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  for (int i = 1; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  long long mini = inf, maxi = -inf;
  for (int i = 0; i < k; i++) {
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  return maxi - mini;
}

int main() {
  scanf("%lld %d", &n, &k);
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  if (satu() == inf && dua() == inf) {
    puts("-1");
    return 0;
  }
  if (satu() < dua()) {
    satu();
    for (int i = 0; i < k; i++) printf("%lld ", a[i]);
  } else {
    dua();
    for (int i = 0; i < k; i++) printf("%lld ", a[i]);
  }

  return 0;
}
