#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

int main() {
  scanf("%d %I64d", &n, &k);
  k--;
  long long ans = n;
  int kira = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(((k >> i) & 1) != kira) {
      ans += (1LL << (i + 1)) - 1;
      kira = ((k >> i) & 1);
    }
    kira ^= 1;
  }
  cout << ans << endl;
  return 0;
}