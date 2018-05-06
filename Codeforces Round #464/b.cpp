
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  long long n; int k;
  scanf("%lld %d", &n, &k);
  long long ans = -1;
  int type;
  long long num;
  for (int i = 0; i < k; i++) {
    scanf("%lld", a + i);
    long long buy = n / a[i];
    if (buy * a[i] > ans) {
      ans = buy * a[i];
      type = i + 1;
      num = buy;
    }
  }
  printf("%d %lld\n", type, num);
  return 0;
}
