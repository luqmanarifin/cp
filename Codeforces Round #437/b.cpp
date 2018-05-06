
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long s[N], a[N], b[N], need[N];
int n, S;
pair<int, int> v[N];

pair<long long, int> solve(long long A, long long B) {
  //printf("now %lld %lld\n", A, B);
  long long pa = A * S;
  long long pb = B * S;
  // A - B, s, A, B
  for (int i = 0; i < n; i++) {
    v[i] = make_pair(a[i] - b[i], i);
    need[i] = s[i];
  }
  sort(v, v + n);
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    int dif = v[i].first;
    int id = v[i].second;
    if (dif > 0) break;
    long long del = min(pb, need[id]);
    pb -= del;
    need[id] -= del;
    ret += del * b[id];
  }
  for (int i = n - 1; i >= 0; i--) {
    int dif = v[i].first;
    int id = v[i].second;
    if (dif < 0) break;
    long long del = min(pa, need[id]);
    pa -= del;
    need[id] -= del;
    ret += del * a[id];
  }
  long long need_a = 0, need_b = 0;
  for (int i = 0; i < n; i++) {
    int dif = v[i].first;
    int id = v[i].second;

    long long del = min(pb, need[id]);
    pb -= del;
    need[id] -= del;
    ret += del * b[id];
    need_b += del;

    del = min(pa, need[id]);
    pa -= del;
    need[id] -= del;
    ret += del * a[id];
    need_a += del;
  }
  //printf("best %lld\n", ret);
  return {ret, need_a > 0};
}

int main() {
  scanf("%d %d", &n, &S);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", s + i, a + i, b + i);
    tot += s[i];
  }
  long long pizzas = tot / S + (tot % S? 1 : 0);
  //cout << "buy " << pizzas << endl;
  long long l = 0, r = pizzas;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    auto ret = solve(mid, pizzas - mid);
    //printf("%lld %lld\n", lf, rf);
    if (ret.second) {
      r = mid;
    } else {
      l = mid;
    }
  }
  long long ans = -1;
  for (long long i = l; i <= r; i++) {
    ans = max(ans, solve(i, pizzas - i).first);
  }
  cout << ans << endl;
  return 0;
}
