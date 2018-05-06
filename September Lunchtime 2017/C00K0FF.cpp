
#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main() {
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    int n;
    cin >> n;
    while (n--) {
      string s;
      cin >> s;
      mp[s]++;
    }
    puts(mp["cakewalk"] && mp["simple"] && mp["easy"] && mp["easy-medium"] + mp["medium"] && mp["medium-hard"] + mp["hard"]? "Yes": "No");
  }

  return 0;
}
