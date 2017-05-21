#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool is[N];
vector<int> prime, ans;

int get(int n) {
  int ret = 0;
  for (auto it : prime) {
    if (n % it == 0) {
      ret++;
      while (n % it == 0) n /= it;
    }
    if (n == 1) return ret;
  }
  return ret;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      prime.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  for (int i = 30; ans.size() < 1000; i++) {
    if (get(i) >= 3) {
      ans.push_back(i);
    }
    //printf("%d ", ans.size());
  }
  //cout << ans.back() << endl;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n - 1]);
  }
  return 0;
}
