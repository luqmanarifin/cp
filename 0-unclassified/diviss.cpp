#include <bits/stdc++.h>

using namespace std;

long long kpk(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

int main() {
  long long n;
  cin >> n;
  long long all = 1;
  for(int i = 2; i <= 10; i++) all = kpk(all, i);
  cout << n / all << endl;
  return 0;
}