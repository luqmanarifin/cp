#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int v;
    scanf("%d", &v);
    if (v != 0) {
      s.insert(v);
    }
  }
  cout << s.size() << endl;
  return 0;
}
