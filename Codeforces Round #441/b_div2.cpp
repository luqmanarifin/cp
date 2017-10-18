#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> p[N];
int a[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[a[i] % m].push_back(a[i]);
  }
  for (int t = 0; t < m; t++) {
    if (p[t].size() >= k) {
      puts("Yes");
      for (int i = 0; i < k; i++) printf("%d ", p[t][i]);
      return 0;
    }
  }
  puts("No");
  return 0;
}
