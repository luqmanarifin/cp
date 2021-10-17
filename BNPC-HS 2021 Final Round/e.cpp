#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7;

vector<pair<int, int>> ev[N]; // length -> (index, become)
int val[N], a[N];

vector<pair<int, int>> s;  // until - become

void dfs(int at, int x) {
  if (s.empty()) {
    s.emplace_back(at, x);
    return;
  }
  if (s.back().first < at) {
    dfs(s.back().first, __gcd(s.back().second, x));
  } else {
    if (x < s.back().second) {
      s.pop_back();
      if (s.empty()) {
        dfs(1, x);
      } else {
        dfs(s.back().first, __gcd(x, s.back().second));
      }
    }
  }
  if (s.back().second < x) {
    s.emplace_back(at, x);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum += a[i];
    val[i] = a[i];
  }

  for (int i = 1; i <= n; i++) {
    // adjusting
    dfs(i, a[i]);

    // putting into event
    for (int j = (int) s.size() - 2; j >= 0; j--) {
      int len = i - s[j+1].first + 2;
      ev[len].emplace_back(i, s[j].second);
    }
  }

  long long ans = 1;
  for (int len = 1; len <= n; len++) {
    // adjusting
    for (auto it : ev[len]) {
      sum += it.second - val[it.first];
      val[it.first] = it.second;
    }

    // getting answer
    ans *= sum % mod;
    ans %= mod;
    sum -= val[len];
  } 
  cout << ans << endl;
  return 0;
}
