#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
bool is[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (is[i]) continue;
    for (int j = i; j < N; j += i) {
      if (is[j] == 0) {
        is[j] = i;
      }
    }
  }
  a[1] = 1;
  for (int i = 2; i < N; i++) {
    vector<pair<int, int>> p; // num - cnt
    int x = i;
    while (x > 1) {
      if (!p.empty() && p.back().first == is[x]) {
        p.back().second++;
      } else {
        p.emplace_back(is[x], 1);
      }
      x /= is[x];
    }
    int ans = 1;
    for (auto it : p) ans *= (it.second + 1);
    a[i] = ans;
  }
  int n;
  scanf("%d", &n);
  puts(a[n] == 5? "YES" : "NO");
  return 0;
}
