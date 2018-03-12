#include <bits/stdc++.h>

using namespace std;

int main() {
  int a[] = {2, 5, 7, 7, 9, 10};
  cout << (lower_bound(a, a + 6, 2) - a) << endl;
  cout << (lower_bound(a, a + 6, 3) - a) << endl;
  cout << (lower_bound(a, a + 6, 99) - a) << endl;
  
  cout << (upper_bound(a, a + 6, 7) - a) << endl;
  
  
  return 0;
}
