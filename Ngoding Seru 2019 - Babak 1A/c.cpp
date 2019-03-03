#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

const int N = 1e6 + 5;

int is[N];
vector<int> s[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (int j = i; j < N; j += i) {
        is[j] = i;
      }
    }
  }
  puts("sieve done");
  long long tot = 0, relative_prime = 0;
  vector<int> num;
  for (int i = 1; i < N; i++) {
    tot += i;
    int now = i;
    vector<int> p;
    while (now > 1) {
      int prime = is[now];
      while (now % prime == 0) now /= prime;
      p.push_back(prime);
    }
    sort(p.begin(), p.end());
    long long tau = i;
    for (auto it : p) {
      tau = tau / it * (it - 1);
    }
    relative_prime += tau;
    num.push_back(i - tau);
  }
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  long long ans = 0;
  for (int i = 0; i < 100000; i++) ans += num[i];
  cout << ans << endl;
  cout << tot << endl;
  cout << "prime " << relative_prime << endl;
  cout << tot - relative_prime << endl;

  return 0;
}
