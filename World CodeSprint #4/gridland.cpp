#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const long long PRIME[] = {71, 93};
const long long mod[] = {(long long) 1e9 + 7, (long long) 2e9 + 89};

vector<long long> all;
char st[2 * N];
int n;

void add() {
  long long now[2] = {};
  for(int i = 0; i < 2 * n; i++) {
    for(int j = 0; j < 2; j++) {
      now[j] = (now[j] * PRIME[j] + st[i] - 'a' + 1) % mod[j];
    }
  }
  //for(int i = 0; i < 2 * n; i++) printf("%c", st[i]); printf("\n");
  long long v = now[0] * mod[1] + now[1];
  all.push_back(v);
}

int find() {
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  return all.size();
}

// kolom - baris - kesediaan
string s[N][2][2];
char a[2][N];

void kolang_kaling(int pt, int p, int q, int r) {
  if(r == 0) {
    int qn = q;
    for(int i = p; i < n; i++) {
      string str = s[i][qn][r];
      for(int j = 0; j < str.length(); j++) {
        st[pt + j] = str[j];
      }
      add();
      st[pt++] = a[qn][i];
      st[pt++] = a[qn ^ 1][i];
      qn ^= 1;
    }
  } else {
    int qn = q;
    for(int i = p; i >= 0; i--) {
      string str = s[i][qn][r];
      for(int j = 0; j < str.length(); j++) {
        st[pt + j] = str[j];
      }
      add();
      st[pt++] = a[qn][i];
      st[pt++] = a[qn ^ 1][i];
      qn ^= 1;
    }
  }
}

void solve_tengah(int p, int q) {
  string l, r;
  for(int i = p; i >= 0; i--) l.push_back(a[q][i]);
  for(int i = 0; i <= p; i++) l.push_back(a[q ^ 1][i]);
  int pt = 0;
  for(int i = 0; i < l.length(); i++) st[pt++] = l[i];
  kolang_kaling(pt, p + 1, q ^ 1, 0);
  
  for(int i = p; i < n; i++) r.push_back(a[q][i]);
  for(int i = n - 1; i >= p; i--) r.push_back(a[q ^ 1][i]);
  pt = 0;
  for(int i = 0; i < r.length(); i++) st[pt++] = r[i];
  kolang_kaling(pt, p - 1, q ^ 1, 1);
}

void solve_pojok(int p, int q, int r) {
  kolang_kaling(0, p, q, r);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    all.clear();
    
    scanf("%d %s %s", &n, a[0], a[1]);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 2; j++) {
        string f;
        for(int k = i; k < n; k++) f.push_back(a[j][k]);
        for(int k = n - 1; k >= i; k--) f.push_back(a[j ^ 1][k]);
        string g;
        for(int k = i; k >= 0; k--) g.push_back(a[j][k]);
        for(int k = 0; k <= i; k++) g.push_back(a[j ^ 1][k]);
        s[i][j][0] = f;
        s[i][j][1] = g;
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
    printf("%d\n", find());
  }
  
  return 0;
}
