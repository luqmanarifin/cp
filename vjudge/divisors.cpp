#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long cnt[N], sum[N];
int last[N];
vector<long long> ncnt[2005], nsum[2005];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if (b & 1) {
    tmp = tmp * a;
  }
  return tmp;
}

long long arith(int a, int r, int n) {
  return a * (power(r, n) - 1) / (r - 1);
}

pair<long long, long long> solve(int til, int k) {
  til = til / k;
  return {ncnt[k][til], nsum[k][til]};
}

int main() {
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      last[i] = i;
      for (long long j = 1LL * i * i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  cnt[1] = sum[1] = 1;
  for (int i = 2; i < N; i++) {
    int p = last[i];
    int ada = 0;
    int now = i;
    while (now % p == 0) {
      now /= p;
      ada++;
    }
    cnt[i] = cnt[now] * (ada + 1);
    sum[i] = sum[now] * arith(1, p, ada + 1);
  }
  for (int i = 1; i <= 2000; i++) {
    ncnt[i].push_back(0);
    nsum[i].push_back(0);
    long long now_cnt = 0, now_sum = 0;
    for (int j = i; j < N; j += i) {
      now_cnt += cnt[j];
      now_sum += sum[j];
      ncnt[i].push_back(now_cnt);
      nsum[i].push_back(now_sum);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    auto rig = solve(b, k);
    auto lef = solve(a - 1, k);
    rig.first -= lef.first;
    rig.second -= lef.second;
    printf("%lld %lld\n", rig.first, rig.second);
  }
  return 0;
}
