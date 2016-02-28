#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, t;
  scanf("%lld %lld %lld", &a, &b, &t);
  long long v = b - a;
  cout << t * v << endl;
  return 0;
}