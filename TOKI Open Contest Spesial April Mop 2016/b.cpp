#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if(n == 1) {
    cout << n << endl;
  } else if(n % 2 == 0) {
    cout << n/2+1 << endl;
  } else {
    cout << n/2+2 << endl;
  }
  
  return 0;
}
