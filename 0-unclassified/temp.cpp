#include <bits/stdc++.h>

using namespace std;

#define to_string( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

const int N = 1005;
const int awal = 10000;
const int goal = 64975;

const int inf = 1e9;

int dp[goal * 10];
int back[goal * 10];

void backtrack(int now) {
  if(now == awal) {
    printf("%d ", now);
    return;
  }
  backtrack(back[now]);
  printf("%d ", now);
}

int main() {
  for(int i = 0; i <= goal; i++) {
    dp[i] = inf;
  }
  dp[awal] = 0;
  for(int i = awal; i <= goal; i++) {
    string s = to_string(i);
    reverse(s.begin(), s.end());
    int rev = atoi(s.c_str());
    if(dp[i] + 1 <= dp[i + 1]) {
      dp[i + 1] = dp[i] + 1;
      back[i + 1] = i;
    }
    if(dp[i] + 1 < dp[rev]) {
      dp[rev] = dp[i] + 1;
      back[rev] = i;
    }
  }
  printf("need %d\n", dp[goal]);
  printf("path :  ");
  backtrack(goal);
  printf("\n");
  return 0;
}
