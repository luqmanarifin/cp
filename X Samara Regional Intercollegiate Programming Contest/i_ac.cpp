#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

struct matrix {
  matrix() {}
  matrix(vector<vector<long long>> m) : a(m) {}
  matrix(const matrix& m) {
    this->a = m.a;
  }
  matrix& operator=(const matrix& m) {
    this->a = m.a;
    return *this;
  }
  matrix operator* (matrix other) {
    int this_n = a.size();
    int this_m = a[0].size();
    int other_n = other.a.size();
    int other_m = other.a[0].size();
    assert(this_m == other_n);
    matrix ret;
    ret.a.assign(this_n, vector<long long>(other_m));
    for (int i = 0; i < this_n; i++) {
      for (int j = 0; j < other_m; j++) {
        for (int k = 0; k < this_m; k++) {
          ret.a[i][j] += a[i][k] * other.a[k][j];
          ret.a[i][j] %= mod;
        }
      }
    }
    return ret;
  }
  bool operator==(const matrix& other) {
    int this_n = a.size();
    int this_m = a[0].size();
    int other_n = other.a.size();
    int other_m = other.a[0].size();
    if (this_n != other_n || this_m != other_m) return 0;
    for (int i = 0; i < this_n; i++) {
      for (int j = 0; j < other_m; j++) {
        if (this->a[i][j] != other.a[i][j]) return 0;
      }
    }
    return 1;
  }
  bool operator !=(const matrix& other) {
    return !(*this == other);
  }
  void print() {
    printf("print %d %d\n", a.size(), a[0].size());
    for (auto i : a) { for (auto j : i) printf("%I64d ", j); printf("\n"); }
  }
  vector<vector<long long>> a;
};

matrix A, B, C;

int main() {
  int n, val;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    A.a.push_back(vector<long long>());
    for (int j = 0; j < n; j++) {
      scanf("%d", &val);
      A.a[i].push_back(val);
    }
  }
  for (int i = 0; i < n; i++) {
    B.a.push_back(vector<long long>());
    for (int j = 0; j < n; j++) {
      scanf("%I64d", &val);
      B.a[i].push_back(val);
    }
  }
  for (int i = 0; i < n; i++) {
    C.a.push_back(vector<long long>());
    for (int j = 0; j < n; j++) {
      scanf("%I64d", &val);
      C.a[i].push_back(val);
    }
  }
  srand(time(NULL));
  for (int it = 0; it < 1; it++) {
    matrix M;
    for (int i = 0; i < n; i++) {
      M.a.push_back({rand()});
    }
    matrix lef = A * (B * M);
    matrix rig = C * M;
    if (lef != rig) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
