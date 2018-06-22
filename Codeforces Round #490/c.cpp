#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

set<int> ada;
char s[N];
vector<int> pos[26];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  for (int i = 0; i < n; i++) {
    pos[s[i] - 'a'].push_back(i);
    ada.insert(i);
  }
  for (int j = 0; j < 26; j++) {
    for (auto it : pos[j]) {
      if (k == 0) break;
      k--;
      ada.erase(it);
    }
  }
  for (auto it : ada) printf("%c", s[it]); printf("\n");

  return 0;
}
