#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return b? gcd(b, a % b) : a;
}

int main() {
  long long a, b;
  //cin >> a >> b;
  //cout << 1000000000000000+2701635667978012-123456789 << endl;
  //cout << 123456789876532+666666666666666-89814029201345 << endl;
  long long fpb = gcd(1000000000000000+2701635667978012-123456789, 123456789876532+666666666666666-89814029201345);
  //cout << fpb << endl;
  cin >> a >> b;
  cout << (a + b) % fpb << endl;;
  return 0;
}
