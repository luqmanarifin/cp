#include <bits/stdc++.h>

using namespace std;

string ori, s;

int main() {
  cin >> s;
  ori = s;
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ori[i]) continue;
    for (int j = i + 1; j < s.size(); j++) {
      if (ori[i] == s[j]) {
        if (s[i] > s[j]) {
          printf("%d %d\n", i + 1, j + 1);
        } else {
          printf("%d %d\n", j + 1, i + 1);
        }
        swap(s[i], s[j]);
        break;
      }
    }
  }
  return 0;
}
