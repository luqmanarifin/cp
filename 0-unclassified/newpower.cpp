#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  cout << min(min(e - a, c - e), min(f - b, d - f)) + 1 << endl;
  
  return 0;
}
