#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.15f\n", (double) sqrt((a - c)*(a - c) + (b - d)*(b - d)));
  return 0;
}
