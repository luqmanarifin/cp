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

int a[5];

int main() {
  int x;
  scanf("%d %d %d %d", &x, a, a + 1, a + 2);
  sort(a, a + 3);
  int tot = a[0] + a[1] + a[2];
  int base = x / tot * 3;
  int rem = x % tot;
  for (int i = 0; i < 3; i++) {
    if (rem >= a[i]) {
      rem -= a[i];
      base++;
    }
  }
  cout << base << endl;
  return 0;
}
