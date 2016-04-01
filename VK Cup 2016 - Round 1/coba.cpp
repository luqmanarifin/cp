#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b) {
  long long tmp = 1, ans = 1;
  while(b) {
    if(b & 1) {
      ans = tmp = ans * a;
    }
    a *= a;
    b /= 2;
  }
  return ans;
}

int main() {
  for(int i = 0; i < 10; i++) {
    cout << power(2, i) << endl;
  }
  
  return 0;
}
