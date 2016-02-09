#include <bits/stdc++.h>

using namespace std;

long long f(long long a, long long b) {
  assert(a >= b);
  if(a == b) return 1;
  if(a % b == 0) return a / b;
  long long jadi = a / b;
  return jadi + f(b, a - jadi * b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << f(max(a, b), min(a, b)) << endl;
  return 0;
}
