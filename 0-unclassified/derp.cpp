#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i <= m; i++) {
    if(a[i - 1] + a[i] + a[i + 1] >= n) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
