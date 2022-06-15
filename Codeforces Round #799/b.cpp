#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      s.insert(a[i]);
    }
    int dup = n - s.size();
    if (dup % 2) dup++;
    printf("%d\n", n - dup);
  }

  return 0;
}
