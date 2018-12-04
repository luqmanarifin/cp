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
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    long long d;
    scanf("%d %d %lld", &a, &b, &d);
    d = d * d;
    printf("%lld", d / 2);
    if (d % 2) printf(".5");
    printf("\n");
  }
  return 0;
}
