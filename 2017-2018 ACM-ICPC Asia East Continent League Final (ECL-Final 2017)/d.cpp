#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;
const int DIGIT = 16;

const long long overflow = 1e18L;

long long ten[20];
vector<long long> factors[N];
vector<long long> ans;

int dig(long long a) {
  if (a == -1) return 0;
  if (a < 10) return 1;
  return 1 + dig(a / 10);
}

long long gcd(long long a, long long b) {
  return b == 0? a : gcd(b, a % b);
}

main() {
  ten[0] = 1;
  for (int i = 1; i < 20; i++) ten[i] = ten[i - 1] * 10;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      factors[j].push_back(i);
    }
  }
  //~ cout << dig(555) << endl;
  for (int st = 1; st < N; st++) {
    for (auto b : factors[st]) {
      if (st % (b * b)) continue;
      for (long long a = b + 1; ; a++) {
        if (gcd(a, b) != 1) continue;
        if (overflow / (st / b / b) < a * a) break;
        int digs = dig(st) + dig(st / b * a) + dig(st / b / b * a * a);
        if (digs > DIGIT) break;
        long long now = st, baru = st / b * a, last = st;
        for (int i = 0; i < 2; i++) {
          now = now * ten[dig(baru)] + baru;
          last = baru;
          baru = baru / b * a;
        }
        //~ if (now == 124820) {
          //~ printf("st %lld b %lld a %lld seq %lld now %lld digs %lld\n", st, b, a, 3, now, digs);
        //~ }
        ans.push_back(now);
        int ada = 3;
        while (digs + dig(baru) <= DIGIT && last % b == 0) {
          ada++;
          //~ if (now == 124820) {
            //~ printf("st %lld b %lld a %lld seq %lld\n", st, b, a, ada);
          //~ }
          digs += dig(baru);
          now = now * ten[dig(baru)] + baru;
          ans.push_back(now);
          last = baru;
          baru = baru / b * a;
        }
      }
    }
  }
  //~ cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
  for (int i = 1; i < ans.size(); i++) assert(ans[i-1] != ans[i]);
  
  int t;
  scanf("%lld", &t);
  for (int tt = 1; tt <= t; tt++) {
    long long l, r;
    scanf("%lld %lld\n", &l, &r);
    printf("Case #%lld: %lld\n", tt, (long long)(upper_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l)));
    auto it = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
    //~ for (int i = it; i < ans.size() && ans[i] <= r; i++) printf("%lld ", ans[i]); printf("\n");
  }
  return 0;
}
