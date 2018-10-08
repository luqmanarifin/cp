#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    int n = s.length();
    long long a = atoll(s.substr(0, n - 1).c_str());
    long long b = atoll(s.substr(n - 1, 1).c_str());
    cout << a + b << endl;
  }
  
  return 0;
}
