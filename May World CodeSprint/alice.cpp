#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int g = (a > d) + (b > e) + (c > f);
  int h = (a < d) + (b < e) + (c < f);
  cout << g << ' ' << h << endl;
  return 0;
}