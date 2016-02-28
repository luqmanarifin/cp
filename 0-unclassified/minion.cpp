#include <bits/stdc++.h>

using namespace std;

const int N = 105;

map<string, string> mp;

int main() {
  int n;
  cin >> n;
  while(n--) {
    string a, b, c;
    cin >> a >> b >> c;
    mp[a] = c;
  }
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if(i) printf(" ");
      printf("%s", mp[s].c_str());
    }
    printf("\n");
  }
  return 0;
}
