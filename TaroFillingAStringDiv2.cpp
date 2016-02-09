#include <bits/stdc++.h>

using namespace std;

class TaroFillingAStringDiv2 {
public:
  int getNumber(string s) {
    int inf = 1e9;
    for(int i = 0; i < 55; i++) {
      for(int j = 0; j < 2; j++) {
        dp[i][j] = inf;
      }
    }
    if(s[0] == 'A' || s[0] == 'B') {
      dp[0][s[0]-'A'] = 0;
    } else {
      dp[0][0] = dp[0][1] = 0;
    }
    int n = s.length();
    for(int i = 1; i < n; i++) {
      if(s[i] == 'A' || s[i] == 'B') {
        int t = s[i] - 'A';
        dp[i][t] = min(dp[i][t], dp[i - 1][t] + 1);
        dp[i][t] = min(dp[i][t], dp[i - 1][t ^ 1]);
      } else {
        for(int t = 0; t < 2; t++) {
          dp[i][t] = min(dp[i][t], dp[i - 1][t] + 1);
          dp[i][t] = min(dp[i][t], dp[i - 1][t ^ 1]);
        }
      }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
  }
  int dp[55][2];
};
/*
int main() {
  TaroFillingAStringDiv2 a;
  cout << a.getNumber("??") << endl;
  return 0;
};
*/