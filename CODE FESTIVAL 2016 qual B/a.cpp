#include <bits/stdc++.h>

using namespace std;

string str = "CODEFESTIVAL2016";

string a;

int main() {
  cin >> a;
  int ans = 0;
  for (int i = 0; i < a.length(); i++) {
    ans += a[i] != str[i];
  }  
  cout << ans << endl;
  return 0;
}