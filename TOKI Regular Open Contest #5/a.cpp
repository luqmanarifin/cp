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

const int N = 20;

int main() {
  string a, b;
  cin >> a >> b;
  if (a.find(b) != string::npos) {
    puts("TIDAK");
  } else {
    puts("YA");
    cout << a << endl;
  }

  return 0;
}
