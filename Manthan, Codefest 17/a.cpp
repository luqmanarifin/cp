#include <bits/stdc++.h>

using namespace std;

map<string, bool> done;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    if (!done.count(a)) {
      puts("NO");
    } else {
      puts("YES");
    }
    done[a] = 1;
  }
  return 0;
}
