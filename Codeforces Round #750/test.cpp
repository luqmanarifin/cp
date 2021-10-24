#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a = {2, 3, 4};
  for (auto it : a) {
    a.push_back(it + 1);
    cout << it << endl;
  }

  return 0;
}
