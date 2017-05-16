#include <bits/stdc++.h>

using namespace std;

const int N = 20;

long long ten[N];

int dig(long long a) {
  if (a < 10) return 1;
  return dig(a / 10) + 1;
}

int main() {
  ten[0] = 1;
  for (int i = 1; i < N; i++) ten[i] = ten[i - 1] * 10;
  
  long long n;
  cin >> n;
  long long tmp = n;
  int digit = dig(n);
  vector<int> a;
  while (n) {
    a.push_back(n % 10);
    n /= 10;
  }  
  cout << ((a.back() + 1) * ten[digit - 1]) - tmp << endl;
  return 0;
}
