#include <bits/stdc++.h>

using namespace std;

string s = "HNELAD";

int main() {
  sort(s.begin(), s.end());
  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  return 0;
}
