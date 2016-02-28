#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  reverse(a, a + n);
  int now = 0;
  for(int i = 0; i < n; i++) {
    now += a[i];
    if(now >= m) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
