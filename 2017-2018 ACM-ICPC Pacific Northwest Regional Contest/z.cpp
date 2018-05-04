#include <bits/stdc++.h>

using namespace std;

// mengandung zero atau nggak
bool zero(int n) {
  if (n < 10) return 0;
  int c = n % 10;
  if (c == 0) return 1;
  return zero(n / 10);
}

int main() {
  int n;
  cin >> n;
  ++n;
  while (zero(n)) n++;
  cout << n << endl;
  return 0;
}
