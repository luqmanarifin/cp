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

long long find(long long a, long long b) {
  return a % b == 0? a / b : a / b + 1;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  cout << find(2LL * n, k) + find(5LL * n, k) + find(8LL * n, k) << endl;
  return 0;
}
