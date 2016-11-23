#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k, s, t;
pair<int, int> p[N];
int a[N];

bool can(int tank) {
  long long need_time = 0;
  for (int i = 0; i < k; i++) {
    int len = (i? a[i] - a[i - 1] : a[i]);
    if (tank < len) return 0;
    int acc = min(tank - len, len);
    int nor = len - acc;
    need_time += acc + 2 * nor;
  }  
  return need_time <= t;
}

int main() {
  scanf("%d %d %d %d", &n, &k, &s, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", a + i);
  }
  sort(p, p + n);
  sort(a, a + k);
  a[k] = s;
  k++;
  
  for (int i = 1; i < n; i++) {
    p[i].second = max(p[i].second, p[i - 1].second);
  }
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(p[mid].second)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (can(p[l].second)) {
    printf("%d\n", p[l].first);
  } else {
    puts("-1");
  }
  return 0;
}
