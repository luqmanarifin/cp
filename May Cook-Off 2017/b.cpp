#include <bits/stdc++.h>

using namespace std;

const int N = 32000;
const int mod = 1e9 + 7;

bool is[N];
int id[N];
vector<int> p;
int cnt[N];

int a[N];
map<int, int> rem;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      id[i] = p.size();
      p.push_back(i);
      for (int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n, val;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    for (int j = 0; j < p.size() && p[j] * p[j] <= val; j++) {
      while (val % p[j] == 0) {
        cnt[p[j]]++;
        val /= p[j];
      }
    }
    if (val > 1) {
      if (val < N) {
        cnt[val]++;
      } else {
        rem[val]++;
      }
    }
  }
  bool good = 1;
  for (auto it : p) if (cnt[it] % n) {
    good = 0;
  }
  for (auto it : rem) if (it.second % n) {
    good = 0;
  }
  if (good) {
    puts("justdoit");
    return 0;
  }
  long long ans = 1;
  for (auto it : p) if (cnt[it] % (n + 1)) {
    int need = n + 1 - (cnt[it] % (n + 1));
    ans = ans * power(it, need) % mod;
  }
  for (auto it : rem) if (it.second % n) {
    int need = n + 1 - (it.second % (n + 1));
    ans = ans * power(it.first, need) % mod;
  }
  cout << ans << endl;
  return 0;
}
