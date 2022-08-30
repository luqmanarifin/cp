#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

string s[3][N];
int score[3];

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(score, 0, sizeof(score));

    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        cin >> s[i][j];
      }
    }
    map<string, int> cnt;
    for (int i = 0; i < 3; i++) {
      map<string, bool> ada;
      for (int j = 0; j < n; j++) {
        ada[s[i][j]] = 1;
      }
      for (auto it : ada) {
        cnt[it.first]++;
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < 3; i++) {
        if (cnt[s[i][j]] == 1) {
          score[i] += 3;
        } else if (cnt[s[i][j]] == 2) {
          score[i] += 1;
        } else {
          score[i] += 0;
        }
      }
    }
    printf("%d %d %d\n", score[0], score[1], score[2]);
  }

  return 0;
}
