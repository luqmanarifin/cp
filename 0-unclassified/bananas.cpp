#include <bits/stdc++.h>

using namespace std;

long long sum(long long a) {
  return a * (1 + a) / 2;
}

int main() {
  long long k, n, w;
  scanf("%I64d %I64d %I64d", &k, &n, &w);
  cout << max(0LL, sum(w) * k - n) << endl;
  
  return 0;
}
