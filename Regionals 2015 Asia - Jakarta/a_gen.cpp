#include <bits/stdc++.h>

using namespace std;

char s[] = "=+-";
string str[] = {"==", "+", "-"};

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int cnt = (i == 0) + (j == 0) + (k == 0);
        if (cnt == 0) continue;
        printf("if (a %s b %s c %s d) e = '%c', f = '%c', g = '%c';\n", str[i].c_str(), str[j].c_str(), str[k].c_str(), s[i], s[j], s[k]);
      }
    }
  }

  return 0;
}
