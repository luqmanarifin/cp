
#include <bits/stdc++.h>

using namespace std;

vector<int> f = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> s;

int main() {
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < f.size(); j++) {
      s.push_back(f[j] + (i == 5 && j == 1));
    }
  }
  //for (auto it : s) printf("%d ", it); printf("\n");
  int n;
  scanf("%d", &n);
  vector<int> a;
  while (n--) {
    int v;
    scanf("%d", &v);
    a.push_back(v);
  }
  //for (auto it : a) printf("%d ", it); printf("\n");
  for (int i = 0; i + a.size() <= s.size(); i++) {
    bool ok = 1;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] != s[i + j]) {
        //printf("%d %d\n", i, i + j);
        ok = 0;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
