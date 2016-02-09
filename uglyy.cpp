// too easy to AC
#include <bits/stdc++.h>

using namespace std;

long long sm, bg, a, l, r, all;

int main() {
  cin >> a >> l >> r;
  for(int i = 62; i >= 0; i--) {
    all |= (1LL << i);
    long long wb = (a ^ (bg | (1LL << i))) & all;
    if((l & all) <= wb && wb <= (r & all)) {
      bg |= (1LL << i);
    }
    long long ws = (a ^ sm) & all;
    if((l & all) <= ws && ws <= (r & all)) {
      
    } else {
      sm |= (1LL << i);
    }
  }
  cout << sm << ' ' << bg << endl;
  return 0;
}
