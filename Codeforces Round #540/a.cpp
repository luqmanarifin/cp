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

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    long long ans = min(n * a, (n / 2) * b + (n % 2) * a);
    printf("%lld\n", ans);
  }

  return 0;
}
