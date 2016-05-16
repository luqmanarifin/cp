#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  for(int i = 0; i < 5; i++) {
    a[i] = i;
  }
  set<tuple<int, int, int, int>> s;
  do {
    int dif = a[0] * 1 + a[1] * 2 - a[2] * 1 - a[3] * 2;
    if(!s.count(make_tuple(a[0], a[1], a[2], a[3]))) {
      cout << dif << endl;
    }
    s.insert(make_tuple(a[0], a[1], a[2], a[3]));
    s.insert(make_tuple(a[2], a[3], a[0], a[1]));
  } while(next_permutation(a, a + 5));
  return 0;
}