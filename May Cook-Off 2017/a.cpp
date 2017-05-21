#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string buf;
    int v;
    for (int i = 0; i < 4; i++) {
      cin >> buf >> v;
      m[buf] = v;
    }    
    if (m["Malaga"] > m["RealMadrid"] && m["Barcelona"] > m["Eibar"]) {
      puts("Barcelona");
    } else {
      puts("RealMadrid");
    }
  }

  return 0;
}
