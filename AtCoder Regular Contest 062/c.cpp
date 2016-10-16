#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long a, b;
  scanf("%d %lld %lld", &n, &a, &b);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    long long big = max(a / u + (a % u? 1 : 0), b / v + (b % v? 1 : 0));
    a = u * big;
    b = v * big;
  }
  cout << a + b << endl;
  return 0;
}
