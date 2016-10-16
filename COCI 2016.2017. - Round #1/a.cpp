#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += k;
    int v;
    scanf("%d", &v);
    now -= v;
    now = max(now, 0);
  }
  cout << now + k << endl;
  return 0;
}
