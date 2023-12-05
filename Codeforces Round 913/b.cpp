#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];  
bool skip[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; i++) skip[i] = 0;

    vector<int> big, small;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        if (small.size()) {
          skip[small.back()] = 1;
          small.pop_back();
        }
        skip[i] = 1;
      } else if (s[i] == 'B') {
        if (big.size()) {
          skip[big.back()] = 1;
          big.pop_back();
        }
        skip[i] = 1;
      } else {
        if ('a' <= s[i] && s[i] <= 'z') {
          small.push_back(i);
        } else {
          big.push_back(i);
        }
      }
    }
    for (int i = 0; i < n; i++) if (!skip[i]) printf("%c", s[i]); printf("\n");
  }

  return 0;
}
