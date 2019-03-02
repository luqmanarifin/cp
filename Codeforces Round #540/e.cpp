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
  long long n, k;
  scanf("%lld %lld", &n, &k);
  if (1LL * k * (k - 1) < n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int par = 1; par < k; par++) {
    for (int i = 0; i < k; i++) {
      int j = (i + par) % k;
      printf("%d %d\n", i + 1, j + 1);
      n--;
      if (n == 0) return 0;
    }
  }

  return 0;
}
