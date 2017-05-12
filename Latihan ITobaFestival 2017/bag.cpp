#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];
pair<int, int> p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) {
    ans[i] = 1;
    p[i] = {a[i], i};
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    int at = p[i].second;
    if (at + 1 < n && a[at + 1] < a[at]) {
      ans[at] = max(ans[at], ans[at + 1] + 1);
    }
    if (at - 1 >= 0 && a[at - 1] < a[at]) {
      ans[at] = max(ans[at], ans[at - 1] + 1);
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i++) ret += ans[i];
  cout << ret << endl;
  return 0;
}