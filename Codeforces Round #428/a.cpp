#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int given = 0, ada = 0;
  for (int i = 0; i < n; i++) {
    ada += a[i];
    int add = min(8, ada);
    given += add;
    ada -= add;
    if (given >= k) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  puts("-1");
  return 0;
}
