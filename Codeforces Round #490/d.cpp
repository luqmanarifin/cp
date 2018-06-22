#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
vector<int> pos[N];
int ada[N];
int pt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int>> q;     // from, add?, berapa kali
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    pos[a[i] % m].push_back(i);
    ada[a[i] % m]++;
  }
  int need = n / m;
  int j = 0;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (j == i) j = (j + 1) % m;
    while (ada[i] > need) {
      while (ada[j] >= need) j = (j + 1) % m;
      int del = min(ada[i] - need, need - ada[j]);
      ada[i] -= del;
      ada[j] += del;
      // printf("%d taruh %d: %d kali\n", i, j, del);
      int diff = (j + m - i) % m;
      ans += 1LL * del * diff;
      q.emplace_back(i, diff, del);
    }
  }
  sort(q.begin(), q.end());
  for (auto it : q) {
    int from, add, kali;
    tie(from, add, kali) = it;
    for (int i = 0; i < kali; i++) {
      a[pos[from][pt[from]]] += add;
      pt[from]++;
    }
  }
  printf("%lld\n", ans);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  return 0;
}
