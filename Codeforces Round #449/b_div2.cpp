
#include <bits/stdc++.h>

using namespace std;

long long reverse(long long v) {
  vector<int> num;
  while (v) {
    num.push_back(v % 10);
    v /= 10;
  }
  long long ret = 0;
  for (auto it : num) ret = ret * 10 + it;
  return ret;
}

long long dig(int v) {
  if (v < 10) return 1;
  return 1 + dig(v / 10);
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  return a * power(a, b - 1);
}

int main() {
  int k, p;
  scanf("%d %d", &k, &p);
  vector<long long> all;
  for (int i = 1; i <= k; i++) {
    int d = dig(i);
    all.push_back(i * power(10, d) + reverse(i));
  }
  assert(all.size() == k);
  //for (auto it : all) printf("%lld\n", it);
  long long ans = 0;
  for (auto it : all) ans = (ans + it) % p;
  cout << ans << endl;
  return 0;
}
