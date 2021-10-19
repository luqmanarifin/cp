#include <bits/stdc++.h>

using namespace std;

const int HASH = 2;
const long long mod[] = {(long long)1e9 + 4207, (long long)2e9 + 2153};

struct Hash {
  Hash(long long x = 0) {
    num = vector<long long>(HASH, x);
    for (int i = 0; i < HASH; i++) {
      num[i] = x;
      if (num[i] >= mod[i]) {
        num[i] %= mod[i];
      }
    }
  }
  Hash(const Hash& x) {
    num = vector<long long>(HASH);
    for (int i = 0; i < HASH; i++) {
      num[i] = x.num[i];
    }
  }
  bool operator==(const Hash& a) {
    if (num.size() != a.num.size()) return 0;
    for (int i = 0; i < HASH; i++) {
      if (num[i] != a.num[i]) return 0;
    }
    return 1;
  }
  bool operator!= (const Hash& a) {
    return !(*this == a);
  }
  Hash operator+(const Hash& a) {
    Hash res;
    for (int i = 0; i < HASH; i++) {
      res.num[i] = num[i] + a.num[i];
      if (res.num[i] >= mod[i]) {
        res.num[i] -= mod[i];
      }
    }
    return res;
  }
  Hash operator*(const Hash& a) {
    Hash res;
    for (int i = 0; i < HASH; i++) {
      res.num[i] = (num[i] * a.num[i]) % mod[i];
    }
    return res;
  }
  Hash operator-(const Hash& a) {
    Hash res;
    for (int i = 0; i < HASH; i++) {
      res.num[i] = num[i] - a.num[i];
      if (res.num[i] < 0) res.num[i] += mod[i];
    }
    return res;
  }
  Hash operator+(const long long& a) {
    Hash x(a);
    return *(this) + x;
  }
  Hash operator*(const long long& a) {
    Hash x(a);
    return *(this) * x;
  }
  Hash operator-(const long long& a) {
    Hash x(a);
    return *(this) - x;
  }
  void print() {
    for (auto it : num) printf("%lld ", it); printf("\n");
  }
  vector<long long> num;
};

const int N = 5e5 + 5;

char sa[N], sb[N];
Hash a[N], b[N], ten[N];
int lena, lenb, Z[2 * N];

Hash find(int l, int r) {
  int len = r - l + 1;
  return a[r] - (a[l-1] * ten[len]);
}

bool check(int st, int lef, int rig) {
  int p = st, q = st + lef - 1, r = st + lef, s = st + lef + rig - 1;
  if (find(p, q) + find(r, s) == b[lenb]) {
    printf("%d %d\n%d %d\n", p, q, r, s);
    return 1;
  }
  return 0;
}

void z_algorithm(string s) {
  int L = 0, R = 0;
  int n = s.size();
  for (int i = 1; i < n; ++i) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R] == s[R-L]) ++R;
      Z[i] = R-L; --R;
    }
    else {
      int k = i-L;
      if (Z[k] < R-i+1) Z[i] = Z[k];
      else {
        L = i;
        while (R < n && s[R] == s[R-L]) ++R;
        Z[i] = R-L; --R;
      }
    }
  }
}

int main() {
  ten[0] = Hash(1);
  for (int i = 1; i < N; i++) {
    ten[i] = ten[i-1] * 10;
  }
  scanf("%s %s", sa + 1, sb + 1);
  lena = strlen(sa + 1);
  lenb = strlen(sb + 1);
  z_algorithm(string(sb + 1) + string(sa + 1));
  for (int i = 1; i <= lena; i++) {
    int c = sa[i] - '0';
    a[i] = a[i-1] * 10 + c;
  }
  for (int i = 1; i <= lenb; i++) {
    int c = sb[i] - '0';
    b[i] = b[i-1] * 10 + c;
  }
  for (int i = 1; i + lenb - 2 <= lena; i++) {
    // get lenb - 1
    if (i + 2 * (lenb - 1) - 1 <= lena) {
      if (check(i, lenb - 1, lenb - 1)) return 0;
    }
    if (i - lenb + 1 >= 1) {
      if (check(i - lenb + 1, lenb - 1, lenb - 1)) return 0;
    }

    // get lenb
    if (i + lenb - 1 <= lena) {
      int lcp = min(lenb, Z[lenb + i - 1]);
      int other = lenb - lcp;
      if (other >= 1) {
        if (i + lenb + other - 1 <= lena) {
          if (check(i, lenb, other)) return 0;
        }
        if (i - other >= 1) {
          if (check(i - other, other, lenb)) return 0;
        }
      }
      if (other >= 2) {
        if (i + lenb + other - 2 <= lena) {
          if (check(i, lenb, other - 1)) return 0;
        }
        if (i - other + 1 >= 1) {
          if (check(i - other + 1, other - 1, lenb)) return 0;
        }
      }
    }
  }
  assert(0);
  return 0;
}
