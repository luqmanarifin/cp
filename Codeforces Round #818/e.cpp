#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

int prime[N]; // smallest prime factor

vector<pair<int, int>> s;
vector<int> st;

void backtrack(int i, int v) {
  if (i == s.size()) {
    st.push_back(v);
    return;
  }
  int seed = 1;
  for (int c = 0; c <= s[i].second; c++) {
    backtrack(i + 1, v * seed);
    seed *= s[i].first;
  }
}

vector<int> factors(int x) {
  // printf("finding factors %d\n", x);
  s.clear();
  st.clear();
  while (x > 1) {
    int p = prime[x];
    int cnt = 0;
    while (x % p == 0) {
      cnt++;
      x /= p;
    }
    s.emplace_back(p, cnt);
  }
  backtrack(0, 1);
  // printf("factors %d: ", x); for (auto it : st) printf("%d ", it); printf("\n");
  return st;
}

long long lcm(long long a, long long b) {
  return a * b / __gcd(a, b);
}

pair<vector<int>, vector<int>> generate(int sum) {
  auto f = factors(sum);
  vector<int> cnt(f.size(), 0);
  for (int i = (int) f.size() - 2; i >= 0; i--) {
    int cur = sum / f[i] - 1;
    cnt[i] = cur;
    for (int j = i + 1; j + 1 < f.size(); j++) {
      if (f[j] % f[i] == 0) {
        cnt[i] -= cnt[j];
      }
    }
  }
  return make_pair(f, cnt);
}

int main() {
  for (int i = 2; i < N; i++) {
    if (prime[i]) continue;
    for (int j = i; j < N; j += i) {
      prime[j] = i;
    }
  }
  // auto val = generate(100);
  // for (int i = 0; i < val.first.size(); i++) {
  //   printf("%d: %d\n", val.first[i], val.second[i]);
  // }

  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int c = 1; c <= n - 2; c++) {
    int sum = n - c;
    auto val = generate(sum);
    auto f = val.first;
    auto cnt = val.second;
    for (int i = 0; i + 1 < f.size(); i++) {
      ans += lcm(c, f[i]) % mod * cnt[i] % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
