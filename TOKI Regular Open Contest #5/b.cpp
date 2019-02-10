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

const int N = 2005;

bool done[N][N];
int ada[N];

int main() {
  int a, b, m;
  scanf("%d %d %d", &a, &b, &m);
  while (!done[a][b]) {
    done[a][b] = 1;
    ada[a] = ada[b] = 1;
    int c = (a + b) % m;
    a = b;
    b = c;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) ans += ada[i];
  cout << ans << endl;

  return 0;
}
