#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const long long PRIME[] = {71, 93};
const long long mod[] = {(long long) 1e9 + 7, (long long) 2e9 + 89};

long long power[2 * N][2];
vector<long long> all;

// kolom - baris - kesediaan
long long s[N][2][2][2], len[N][2][2];
char a[2][N];
int n;
  
// O(1)
void add(long long* h, int p, int q, int r) {
  long long v[2] = {};
  for(int i = 0; i < 2; i++) {
    v[i] = (h[i] * power[len[p][q][r]][i] + s[p][q][r][i]) % mod[i];
  }
  all.push_back(v[0] * mod[1] + v[1]);
}

// O(1)
long long val(long long h, int i, char c) {
  return (h * PRIME[i] + c - 'a' + 1) % mod[i];
}

// O(n)
void kolang_kaling(long long* h, int p, int q, int r) {
  if(r == 0) {
    int qn = q;
    for(int i = p; i < n; i++) {
      add(h, i, qn, r);
      for(int j = 0; j < 2; j++) {
        h[j] = val(h[j], j, a[qn][i]);
        h[j] = val(h[j], j, a[qn ^ 1][i]);
      }
      qn ^= 1;
    }
  } else {
    int qn = q;
    for(int i = p; i >= 0; i--) {
      add(h, i, qn, r);
      for(int j = 0; j < 2; j++) {
        h[j] = val(h[j], j, a[qn][i]);
        h[j] = val(h[j], j, a[qn ^ 1][i]);
      }
      qn ^= 1;
    }
  }
}

// O(n)
void solve_tengah(int p, int q) {
  long long l[2] = {};
  for(int j = 0; j < 2; j++) {
    for(int i = p; i >= 0; i--) l[j] = val(l[j], j, a[q][i]);
    for(int i = 0; i <= p; i++) l[j] = val(l[j], j, a[q ^ 1][i]);
  }
  kolang_kaling(l, p + 1, q ^ 1, 0);
  
  long long r[2] = {};
  for(int j = 0; j < 2; j++) {
    for(int i = p; i < n; i++) r[j] = val(r[j], j, a[q][i]);
    for(int i = n - 1; i >= p; i--) r[j] = val(r[j], j, a[q ^ 1][i]);
  }
  kolang_kaling(r, p - 1, q ^ 1, 1);
}

// O(n)
void solve_pojok(int p, int q, int r) {
  long long h[2] = {};
  kolang_kaling(h, p, q, r);
}

int main() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < 2 * N; i++) {
    for(int j = 0; j < 2; j++) {
      power[i][j] = power[i - 1][j] * PRIME[j] % mod[j];
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    all.clear();
    memset(s, 0, sizeof(s));
    
    scanf("%d %s %s", &n, a[0], a[1]);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 2; j++) {
        for(int q = 0; q < 2; q++) {
          len[i][j][0] = 0;
          long long f = 0;
          for(int k = i; k < n; k++) {
            f = val(f, q, a[j][k]);
            len[i][j][0]++;
          }
          for(int k = n - 1; k >= i; k--) {
            f = val(f, q, a[j ^ 1][k]);
            len[i][j][0]++;
          }
          s[i][j][0][q] = f;
          
          len[i][j][1] = 0;
          long long g = 0;
          for(int k = i; k >= 0; k--) {
            g = val(g, q, a[j][k]);
            len[i][j][1]++;
          }
          for(int k = 0; k <= i; k++) {
            g = val(g, q, a[j ^ 1][k]);
            len[i][j][1]++;
          }
          s[i][j][1][q] = g;
        }
      }
    }
    solve_pojok(0, 0, 0);
    solve_pojok(0, 1, 0);
    solve_pojok(n - 1, 0, 1);
    solve_pojok(n - 1, 1, 1);
    for(int i = 1; i + 1 < n; i++) {
      solve_tengah(i, 0);
      solve_tengah(i, 1);
    }
    sort(all.begin(), all.end());
    all.resize(distance(all.begin(), unique(all.begin(), all.end())));
    printf("%d\n", all.size());
  }

  return 0;
}
