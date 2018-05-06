
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int num[N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
int* x[N];

int id(int i, int j) {
  return i * m + j;  
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool ok(int u, int v) {
  if (n * m > 10) {
    if (n > m) {
      for (int j = 0; j < m; j++) {
        vector<int> bla, whi; 
        for (int i = 0; i < n; i++) {
          int c = (i + j) % 2;
          if (c == 0) {
            bla.push_back(id(i, j));
          } else {
            whi.push_back(id(i, j));
          }
        }
        sort(bla.begin(), bla.end());
        sort(whi.begin(), whi.end());
        reverse(bla.begin(), bla.end());
        reverse(whi.begin(), whi.end());
        int now = 0;
        for (auto it : bla) x[now++][j] = it;
        for (auto it : whi) x[now++][j] = it;
      }
    } else {
      for (int i = 0; i < n; i++) {
        vector<int> bla, whi; 
        for (int j = 0; j < m; j++) {
          int c = (i + j) % 2;
          if (c == 0) {
            bla.push_back(id(i, j));
          } else {
            whi.push_back(id(i, j));
          }
        }
        sort(bla.begin(), bla.end());
        sort(whi.begin(), whi.end());
        reverse(bla.begin(), bla.end());
        reverse(whi.begin(), whi.end());
        int now = 0;
        for (auto it : bla) x[i][now++] = it;
        for (auto it : whi) x[i][now++] = it;
      }
    }
    return 1;
  }
  n = u;
  m = v;
  int now = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      num[now++] = id(i, j);
    }
  }
  int iter = 0;
  do {
    //printf("iter %d\n", ++iter);
    int now = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        x[i][j] = num[now++];
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int val = x[i][j];
        int ni = val / m;
        int nj = val % m;
        for (int d = 0; d < 4; d++) {
          int ti = i + dx[d];
          int tj = j + dy[d];
          if (valid(ti, tj)) {
            int cek = x[ti][tj];
            int dif = abs(cek - val);
            if (dif != 1 && dif != m) continue;
            if (nj > 0 && val - 1 == cek) {
              ok = 0;
              goto LANJUT;
            }
            if (nj + 1 < m && val + 1 == cek) {
              ok = 0;
              goto LANJUT;
            }
            if (ni > 0 && val - m == cek) {
              ok = 0;
              goto LANJUT;
            }
            if (ni + 1 < n && val + m == cek) {
              ok = 0;
              goto LANJUT;
            }
          }
        }
      }
    }
    if (ok) return 1;
    LANJUT:;
    next_permutation(num, num + n * m);
  } while (1);
  assert(0);
}

int main() {
  srand(time(0));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    x[i] = new int[m + 1];
  }
  if (n == 1) {
    if (m == 2 || m == 3) {
      puts("NO");
      return 0;
    }
  } else if (n == 2) {
    if (m < 4) {
      puts("NO");
      return 0;
    }
  } else if (n == 3) {
    if (m < 3) {
      puts("NO");
      return 0;
    }
  }
  if (n * m <= 10);
  assert(ok(n, m));
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", x[i][j] + 1);
    }
    printf("\n");
  }
  return 0;
}
