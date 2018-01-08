#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n > 29) {
    cout << m << endl;
    return 0;
  }
  cout << (m % (1 << n)) << endl;
  return 0;
}
