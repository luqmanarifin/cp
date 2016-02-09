#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1000;
  cout << n << endl;
  for(int i = 0; i < n - 1; i++) {
    if(i % 2) printf("A");
    else printf("B");
  }
  
  return 0;
}
