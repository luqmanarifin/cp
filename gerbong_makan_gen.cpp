#include <bits/stdc++.h>

using namespace std;

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  for(int i = 2; i <= 707; i += 8) {
    cout << "(\"" << i << "\", \"" << get(9, 20) << "\")," << endl;
  }
  
  return 0;
}
