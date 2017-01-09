#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  vector<int> p;
  for (int i = 1; i <= n; i++) if (a[i]) {
    p.push_back(i);
  }
  if (p.empty()) {
    puts("NO");
    return 0;
  }
  puts("YES");
  printf("%d\n", p.size());
  int bef = 0;
  for (int it = 0; it < p.size(); it++) {
    int til = p[it];
    if (p[it] == p.back()) {
      til = n;
    }
    printf("%d %d\n", bef + 1, til);
    bef = p[it];
  }
  return 0;
}
