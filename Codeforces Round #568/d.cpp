#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;


map<int, int> cnt;
int dif;

void add(int v) {
  cnt[v]++;
  if (cnt[v] == 1) dif++;
}

void rem(int v) {
  cnt[v]--;
  if (cnt[v] == 0) dif--;
}

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    v.emplace_back(a[i], i);
  }
  sort(v.begin(), v.end());
  sort(a, a + n);
  for (int i = 1; i < n; i++) add(a[i] - a[i - 1]);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      rem(a[i+1] - a[i]);
    } else if (i == n - 1) {
      rem(a[n-1] - a[n-2]);
    } else {
      rem(a[i] - a[i-1]);
      rem(a[i+1] - a[i]);
      add(a[i+1] - a[i-1]);
    }
    if (dif <= 1) {
      cout << v[i].second + 1 << endl;
      return 0;
    }
    if (i == 0) {
      add(a[i+1] - a[i]);
    } else if (i == n - 1) {
      add(a[n-1] - a[n-2]);
    } else {
      add(a[i] - a[i-1]);
      add(a[i+1] - a[i]);
      rem(a[i+1] - a[i-1]);
    }
  }
  puts("-1");
  return 0;
}
