
#include <bits/stdc++.h>

using namespace std;

map<long long, bool> done;

int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  for (int i = 1; i <= k; i++) {
    long long d = n % i;
    if (done.count(d)) {
      puts("No");
      return 0;
    }
    done[d] = 1;
  }
  puts("Yes");
  return 0;
}
