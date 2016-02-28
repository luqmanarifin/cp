#include <bits/stdc++.h>

using namespace std;

int f(int i) {
  return i? f(i - 1) * i : 1;
}

int main() {
  int a;
  cin >> a;
  if(0 <= a && a <= 10) cout << f(a) << endl;
  else cout << "ditolak" << endl;
  return 0;
}
