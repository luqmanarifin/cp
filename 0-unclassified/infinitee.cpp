#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  scanf("%I64d", &n);
  long long l = 1, r = 1e8;
  while(l < r) {
    long long mid = (l + r) >> 1;
    long long sum = mid * (mid + 1) / 2;
    if(n <= sum) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << n - l * (l - 1) / 2 << endl;
  return 0;
}