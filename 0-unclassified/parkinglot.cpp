#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if(b & 1) {
    tmp = tmp * a;
  }
  return tmp;
}

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  int k = 2 * n - 2;
  for(int i = 0; i + n <= k; i++) {
    int rem = k - n;
    int sisi = 0;
    if(i) rem--, sisi++;
    if(i + n < k) rem--, sisi++;
    ans += 4 * power(3, sisi) * power(4, rem);
  }
  cout << ans << endl;
  return 0;
}