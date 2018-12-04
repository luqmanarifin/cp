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

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v) {
        ans++;  
      }
    }  
    printf("%d\n", ans);
  }

  return 0;
}
