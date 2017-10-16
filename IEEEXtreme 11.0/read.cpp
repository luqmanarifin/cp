#include <bits/stdc++.h>

using namespace std;

int one[26];
int two[26][26];

vector<pair<int, int>> rule[30][30];
string str = "jqwxz";

int main() {
  for (int i = 0; i < 26; i++) {
    int v;
    scanf("%d", &v);
    one[i] = v;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < str.size(); j++) {
      scanf("%d", &two[i][j]);
      rule[one[i]][two[i][j]].emplace_back(i, str[j] - 'a');
    }
  }
  //cout << one[19] << ' ' << two[19][4] << endl;
  
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++) {
      if (rule[i][j].size()) {
        int x = 4;
        int y = i;
        if (y == 0) continue;
        if (y == 4 && j == 4) continue;
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            if (k * x + l * y == j) {
              for (auto it : rule[i][j]) {
                printf("%d %d %d %d\n", k, l, it.first, it.second);
              }
            }
          }
        }
      }
    }
  }

  return 0;
}
