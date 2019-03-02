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

const int N = 1e5 + 5;

char a[N], b[N]; 

int ca[26], cb[26];


int main() {
  scanf("%s %s", a, b);
  int sa = strlen(a);
  int sb = strlen(b);
  for (int i = 0; i < sa; i++) ca[a[i] - 'A']++;
  for (int i = 0; i < sb; i++) cb[b[i] - 'A']++;
  bool ok = 1;
  for (int i = 0; i < 26; i++) {
    if (ca[i] < cb[i]) {
      ok = 0;
    }
  }
  puts(ok? "YA" : "TIDAK");

  return 0;
}
