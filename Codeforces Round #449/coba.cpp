
#include <bits/stdc++.h>

using namespace std;

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  long long tot = 0;
  int n = 100000;
  for (int i = 1; i <= n; i++) {
    tot += sum(i - 1);
    tot += sum(n - i);
  }
  cout << (double) tot / (1LL * n * n) << endl;
  return 0;
}
