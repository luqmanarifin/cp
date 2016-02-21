#include <bits/stdc++.h>

using namespace std;

int mod = 100;

int power(int a, long long b) {
  if(b == 0) return 1;
  int tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if(b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

int main() {
  long long n;
  cin >> n;
  cout << power(5, n) << endl;
  return 0;
}