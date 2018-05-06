
#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int win = 1;
  int now = max(a[0], a[1]);
  for (int i = 2; i < n; i++) {
    if (now > a[i]) {
      win++;
    } else {
      now = a[i];
      win = 1;
    }
    if (a[i] == n || win == k) break;
  }
  cout << now << endl;
  return 0;
}
