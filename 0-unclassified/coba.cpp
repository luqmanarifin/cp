#include <bits/stdc++.h>

using namespace std;

int main() {
  string a = "aab";
  do {
    cout << a << endl;
  } while (next_permutation(a.begin(), a.end()));

  return 0;
}
