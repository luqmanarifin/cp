#include <bits/stdc++.h>

using namespace std;


bool cmp(pair<long long, vector<long long> > & a, pair<long long, vector<long long> > & b) {
  if (b.first == 0) return 1;
  if (a.first == 0) return 0;
  if (a.first != b.first)
    return a.first < b.first;
  return a.second > b.second;
}

int main() {
  long long a, m, p, q, r, s;
  scanf("%lld %lld %lld %lld %lld %lld", &a, &m, &p, &q, &r, &s);
  for (int tc = 1; (a || m || p || q || r || s); ++tc) {
    printf("Case %d:", tc);
    if (r <= p && q <= s) {
      printf(" empty");
    }
    else if (m == 1) {
      long long k = (max(r - p, 0LL) + a -1) / a;
      long long x = p + a * k, y = q + a * k;
      if (r <= x && y <= s) {
        printf(" %lldA", k);
      }
      else {
        printf(" impossible");
      }
    }
    else {
      pair<long long, vector<long long> > ans (0, {});
      for (long long z = 0, c = 1; q * c <= s; ++z, c *= m) {
        long long k = (max(r - p * c, 0LL) + a -1) / a;
        long long x = p * c + a * k, y = q * c + a * k;
        long long from = k, to = (max(s-q*c, 0LL)) / a;
        long long cc = c;
        if (r <= x && y <= s) {
          vector<long long> vs;
          long long sz = z;
          k = 0;
          for (long long i = z; i >= 0; --i) {
            if (k >= from)
              vs.push_back(0);
            else {
              long long ambil = (from - k + cc - 1)/cc;
              if (k + ambil * cc > to) --ambil;
              vs.push_back(ambil);
            }
            k += cc * vs.back();
            sz += vs.back();
            cc /= m;
          }
          pair<long long, vector<long long> > cur(sz, vs);
          if (cmp(cur, ans))
            ans = cur;
        }
      }
      if (ans.first == 0) {
        printf(" impossible");
      }
      else {
        long long cntm = 0;
        for (int i = 0; i < ans.second.size(); ++i) {
          if (ans.second[i] > 0) {
            if (cntm > 0) {
              printf(" %lldM", cntm);
              cntm = 0;
            }
            printf(" %lldA", ans.second[i]);
          }
          if (i + 1 < ans.second.size())
            ++cntm;
        }
        if (cntm > 0)
          printf(" %lldM", cntm);
      }
    }
    printf("\n");
    scanf("%lld %lld %lld %lld %lld %lld", &a, &m, &p, &q, &r, &s);
  }
  return 0;
}

