#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

string s;

int main() {
  cin >> s;
  vector<int> a;
  for (int i = 0; i + 9 <= s.length(); i++) {
    if (s.substr(i, 9) == "happiness") {
      a.push_back(i);
    }
  }
  int n = s.length();
  srand(time(NULL));
  if (a.size() == 0) {
    puts("YES");
    for (int i = 0; i < s.size(); i++) {
      for (int j = i + 1; j < s.size(); j++) {
        bool good = 1;
        swap(s[i], s[j]);
        for (int k = 0; k <= min((int)s.length() - 9, j); k++) {
          if (s.substr(k, 9) == "happiness") {
            good = 0;
            break;
          }
        }
        swap(s[i], s[j]);
        if (good) {
          printf("%d %d\n", i + 1, j + 1);
          goto TAEK;
        }
      }
    }
    TAEK:;
  } else if (a.size() > 2) {
    puts("NO");
  } else {
    puts("YES");
    int p = a[0], q;
    if (a.size() == 1) q = a[0];
    else q = a[1];
    printf("%d %d\n", p + 1, q + 2);
  }
  return 0;
}
