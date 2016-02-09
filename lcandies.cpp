#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  
  int q;
  cin >> q;
  while(q--) {
    long long n;
    int t;
    cin >> n >> t;
    while(t--) {
      if(n % 2) n = n - (n + 1) / 2;
      else n = n - n / 2;
      n = n - n / 4;
    }
    cout << n << '\n';
  }
  
  return 0;
}
