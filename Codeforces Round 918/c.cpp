#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      sum += v;
    }
    long long sq = sqrt((double) sum + 0.5);
    puts(sq * sq == sum? "YES" : "NO");
  }

  return 0;
}
