
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = (1LL << 32);

int n;

int main() {
  string s, buf;
  while (getline(cin, s)) {
    stringstream ss(s);
    vector<long long> a;
    while (ss >> buf) {
      a.push_back(atoi(buf.c_str()));
    }
    n = a.size();

    long long tot = 0;
    for (int i = 0; i < n; i++) tot += a[i];
    cerr << n << ' ' << tot << ' ' << tot % mod << endl;
    assert((tot + a[1]) % mod == 0);

    long long best = 1e18, p = -1;
    long long nbest = 1e18, np = -1;
    for (int i = 0; i < n; i++) {
      long long cur = (tot + a[i]);
      long long ncur = (tot + a[i]) % mod;
      if (cur < best) {
        best = cur;
        p = i;
      }
      if (ncur < nbest) {
        nbest = ncur;
        np = i;
      }
    }
    if (p == np) {
      printf("kenapa sama? padahal %lld %lld\n", best, nbest);
    }
  }

  return 0;
}
