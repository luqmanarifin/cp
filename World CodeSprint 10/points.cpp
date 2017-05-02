#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  cout << 10 * (min(10, a) + min(10, b) + min(10, c)) << endl;
  return 0;
}
