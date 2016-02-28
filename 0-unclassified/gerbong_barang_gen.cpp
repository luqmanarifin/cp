#include <bits/stdc++.h>

using namespace std;

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}


int main() {
  srand(time(NULL));
  for(int i = 1; i <= 707; i += 8) {
    cout << "(\"" << i << "\", \"" << get(40, 45) << "\")," << endl;
  }
  
  return 0;
}
