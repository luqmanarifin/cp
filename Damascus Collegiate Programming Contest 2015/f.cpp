#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    string a, b;
    cin >> a >> b;
    int tot = a.size() + b.size();
    vector<string> p;
    for(int mask = 0; mask < (1 << tot); mask++) {
      if(__builtin_popcount(mask) != b.size()) continue;
      int i = 0, j = 0;
      string str;
      for(int k = 0; k < tot; k++) {
        if(mask & (1 << k)) {
          str.push_back(b[j++]);
        } else {
          str.push_back(a[i++]);
        }
      }
      p.push_back(str);
    }
    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));
    for(auto it : p) printf("%s\n", it.c_str());
    printf("\n");
  }
  
  return 0;
}
