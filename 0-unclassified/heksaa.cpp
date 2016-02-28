#include <bits/stdc++.h>

using namespace std;

long long sigma(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  int n;
  scanf("%d", &n);
  cout << 6 * sigma(n) + 1 << endl;
  return 0;
}