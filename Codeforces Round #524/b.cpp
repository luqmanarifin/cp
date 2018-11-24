#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

long long sum(long long n, long long a, long long b) {
  return n * (2 * a + (n - 1) * b) / 2;
}

long long solve(long long a, long long b) {
  long long ans = 0;

  // ganjil -
  long long l = a, r = b;
  if (l % 2 == 0) l++;
  if (r % 2 == 0) r--;
  if (l <= r) {
    ans -= sum((r - l) / 2 + 1, l, 2);
  }

  // genap +
  l = a, r = b;
  if (l % 2) l++;
  if (r % 2) r--;
  if (l <= r) {
    ans += sum((r - l) / 2 + 1, l, 2);
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", solve(l, r));
  }

  return 0;
}
