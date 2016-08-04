#include <bits/stdc++.h>

using namespace std;

const int N = 105;

pair<int, int> p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    p[i] = {v, i};
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n / 2; i++) {
    printf("%d %d\n", p[i].second, p[n - i + 1].second);
  }
  return 0;
}
