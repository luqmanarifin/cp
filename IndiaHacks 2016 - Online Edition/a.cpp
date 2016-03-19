#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  n = unique(a, a + n) - a;
  for(int i = 0; i + 2 < n; i++) {
    if(a[i] + 2 == a[i + 2]) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
