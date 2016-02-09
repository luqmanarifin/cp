#include <bits/stdc++.h>

using namespace std;

vector<int> num;

long long range(int l, int r) {
  return 1LL * r * (r + 1) / 2 - 1LL * l * (l - 1) / 2;
}

int main() {
  long long n, p, q;
  scanf("%I64d %I64d %I64d", &n, &p, &q);
  long long pol = (n + 1) * n / 2;
  for(int cnt = q; cnt <= n; cnt += q) {
    long long sum = cnt * p / q;
    if(sum > pol) break;
    if(range(1, cnt) <= sum && sum <= range(n - cnt + 1, n)) {
      for(int i = 1; i <= cnt; i++) {
        num.push_back(i);
        sum -= i;
      }
      int k = n;
      for(int i = num.size() - 1; i >= 0; i--) {
        long long add = min(1LL * k - num[i], sum);
        sum -= add;
        num[i] += add;
        k--;
      }
      for(auto it : num) {
        printf("%d ", it);
      }
      return 0;
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}
