#include <bits/stdc++.h>

using namespace std;

vector<int> rem = {2, 3, 6, 7, 8, 10};
vector<int> need = {2, 2, 12, 10, 11, 37};

vector<int> a;

int main() {
  vector<pair<int, string>> all;
  for (int i = 0; i < rem.size(); i++) a.push_back(i);
  do {
    int cur = 0, t = 0;
    string str;
    for (auto it : a) {
      t += need[it];
      cur += t * rem[it];
      str.push_back(it + 'A');
    }
    all.emplace_back(cur, str);
  } while (next_permutation(a.begin(), a.end()));
  sort(all.begin(), all.end());
  for (auto it : all) {
    printf("%d", it.first);
    for (int i = 0; i < it.second.size(); i++) {
      printf(" %c", it.second[i]);
    }
    printf("\n");
  }
  return 0;
}
