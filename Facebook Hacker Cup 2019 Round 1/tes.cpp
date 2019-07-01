#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a = {1,1,1,1,2,3,3};
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  for (auto it : a) cout << it << endl;

  return 0;
}
