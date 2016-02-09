#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long inf = 1e18;

vector<int> num;
int l[N], r[N];
long long dp[2 * N];

int id(int a) {
  return lower_bound(num.begin(), num.end(), a) - num.begin();
}

void print() {
  for(int i = 0; i < num.size(); i++) {
    printf("%I64d ", num[i]);
  }
  printf("\n");
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    num.push_back(l[i]);
    num.push_back(r[i]);
  }
  num.push_back(x);
  num.push_back(0);
  num.push_back(1e9 + 5);
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  
  for(int i = 0; i < 2 * N; i++) dp[i] = inf;
  dp[id(x)] = 0;
  for(int p = 0; p < n; p++) {
    long long now = dp[0];
    for(int i = 1; i < num.size(); i++) {
      now += num[i] - num[i - 1];
      now = min(now, dp[i]);
      dp[i] = now;
    }
    now = dp[num.size() - 1];
    for(int i = num.size() - 2; i >= 0; i--) {
      now += num[i + 1] - num[i];
      now = min(now, dp[i]);
      dp[i] = now;
    }
    //puts("BEFORE :");
    //print();
    for(int i = 0; i < num.size(); i++) {
      if(!(l[p] <= num[i] && num[i] <= r[p])) {
        dp[i] += min(abs(num[i] - l[p]), abs(num[i] - r[p]));
      }
    }
    //puts("AFTER :");
    //print();
  }
  long long ans = inf;
  for(int i = 0; i < num.size(); i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
