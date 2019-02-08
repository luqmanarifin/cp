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
  int n = 5;
  srand(time(0));
  printf("genap = SQ\n");
  printf("ganjil = QZ\n");
  printf("randoming %d times...\n", n);
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int num = rand();
    printf("%d: %d\n", i + 1, num);
    if (num % 2 == 0) {
      a++;
    } else {
      b++;
    }
  }
  if (a > b) {
    printf("SQ aja\n");
  } else {
    printf("Udah AirAsia aja\n");
  }
  return 0;
}
