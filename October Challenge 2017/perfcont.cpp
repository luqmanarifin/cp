
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    int ez = 0, hard = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v >= p / 2) {
        ez++;
      }
      if (v <= p / 10) {
        hard++;
      }
    }
    puts(ez == 1 && hard == 2? "yes" : "no");
  }
  return 0;
}
