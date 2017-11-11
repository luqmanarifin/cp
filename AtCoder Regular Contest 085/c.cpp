#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long elapsed = 1900 * m + 100 * (n - m);
  long long kali = 1;
  for (int i = 0; i < m; i++) kali *= 2;
  cout << elapsed * kali << endl;
  return 0;
}
