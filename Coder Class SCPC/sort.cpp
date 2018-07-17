#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long fact[N], ifact[N];

long long ambil(int n, int k) {
  return fact[n] * ifact[n - k] % mod;
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int get_n(string s) {
  stringstream ss(s);
  vector<string> tokens; string buf;
  while (ss >> buf) {
    tokens.push_back(buf);
  }
  return atoi(tokens[2].c_str());
}

vector<int> extract(string s, int n) {
  stringstream ss(s);
  vector<string> tokens; string buf;
  while (ss >> buf) {
    tokens.push_back(buf);
  }
  vector<int> a = {atoi(tokens[2].c_str())};
  for (int i = 4; i < tokens.size(); i++) {
    a.push_back(atoi(tokens[i].c_str()));
  }
  vector<int> len;
  for (int i = 0; i < a.size(); i++) {
    if (i + 1 < a.size()) {
      len.push_back(a[i + 1] - a[i]);
    } else {
      len.push_back(n - a[i] + 1);
    }
  }
  return len;
}

int main() {
  ios_base::sync_with_stdio(false);
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    int n = get_n(a);
    auto num = extract(b, n);
    long long ans = 1;
    int ada = n;
    for (int i = (int) num.size() - 1; i >= 0; i--) {
      ans *= ambil(ada - 1, num[i] - 1);
      ans %= mod;
      ada -= num[i];
    }
    printf("%lld\n", ans);
  }

  return 0;
}
