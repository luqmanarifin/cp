#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

struct rectangle {
  rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
  int x1, x2, y1, y2;
};

const int N = 1005;

// updated optimally
int ans;
vector<rectangle> answer;

// never change
int n, m;
int T[N][N], M[N][N], each, maks;
char s[N][N];
vector<rectangle> pos;

// per trial
long long dot[N][N], sx[N][N], sy[N][N], sum[N][N];

long long find(long long a[N][N], int i, int j) {
  long long ret = 0;
  for (int p = i; p >= 0; p = (p & (p + 1)) - 1) {
    for (int q = j; q >= 0; q = (q & (q + 1)) - 1) {
      ret += a[p][q];
    }
  }
  return ret;
}

void add(long long a[N][N], int i, int j, long long val) {
  for (int p = i; p <= n; p |= p + 1) {
    for (int q = j; q <= m; q |= q + 1) {
      a[p][q] += val;
    }
  }
}

void add_bit(int i, int j, int val) {
  add(dot, i, j, 1LL * val);
  add(sx, i, j, 1LL * val * -(i - 1));
  add(sy, i, j, 1LL * val * -(j - 1));
  add(sum, i, j, 1LL * val * (i - 1) * (j - 1));
}

int find_bit(int i, int j) {
  long long ret = 0;
  ret += find(dot, i, j) * i * j;
  ret += find(sx, i, j) * j;
  ret += find(sy, i, j) * i;
  ret += find(sum, i, j);
  // printf("%d %d: %lld %lld %lld %lld\n", i, j, find(dot, i, j), find(sx, i, j), find(sy, i, j), find(sum, i, j));
  return ret;
}

void add_rect(int x1, int y1, int x2, int y2) {
  add_bit(x1, y1, +1);
  add_bit(x2 + 1, y1, -1);
  add_bit(x1, y2 + 1, -1);
  add_bit(x2 + 1, y2 + 1, +1);
}

int find_rect(int x1, int y1, int x2, int y2) {
  long long ret = 0;
  ret += find_bit(x2, y2);
  ret -= find_bit(x1 - 1, y2);
  ret -= find_bit(x2, y1 - 1);
  ret += find_bit(x1 - 1, y1 - 1);
  return ret;
}

int get(int bit[N][N], int x1, int y1, int x2, int y2) {
  return bit[x2][y2] - bit[x1-1][y2] - bit[x2][y1-1] + bit[x1-1][y1-1];
}

int main() {
  ans = -1;
  scanf("%d %d %d %d", &n, &m, &each, &maks);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'T') {
        T[i][j]++;
      } else {
        M[i][j]++;
      }
      T[i][j] += T[i-1][j] + T[i][j-1] - T[i-1][j-1];
      M[i][j] += M[i-1][j] + M[i][j-1] - M[i-1][j-1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i; k <= n && k - i + 1 <= maks; k++) {
        int dx = (k - i + 1);
        int dymin = (2 * each + dx - 1) / dx;
        int dymax = maks / dx;
        for (int l = j + dymin - 1; l <= j + dymax - 1 && l <= m; l++) {
          int ct = get(T, i, k, j, l);
          int cm = get(M, i, k, j, l);
          // printf(" %d %d %d %d gain %d\n", i, j, k, l, (k - i + 1) * (l - j + 1));
          if (ct >= each && cm >= each) {
            pos.push_back(rectangle(i, j, k, l));
          }
        }
      }
    }
  }

  srand(time(0));
  // add_rect(2, 2, 2, 5);
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     printf("find bit %d %d: %d\n", i, j, find_bit(i, j));
  //     // printf("%d %d %d %d: %d\n", i, j, i, j, find_rect(i, j, i, j));
  //     for (int k = i; k <= n; k++) {
  //       for (int l = j; l <= m; l++) {
  //         // printf("%d %d %d %d: %d\n", i, j, k, l, find_rect(i, j, k, l));
  //       }
  //     }
  //   }
  // }
  // return 0;
  for (int it = 0; it < 10; it++) {
    cerr << "iterasi " << it << endl;
    vector<rectangle> cur;
    int got = 0;
    random_shuffle(pos.begin(), pos.end());
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dot[i][j] = sx[i][j] = sy[i][j] = sum[i][j] = 0;
      }
    }
    for (auto it : pos) {
      int x1 = it.x1;
      int x2 = it.x2;
      int y1 = it.y1;
      int y2 = it.y2;
      // printf("%d %d %d %d: %d %d %d\n", x1, y1, x2, y2, get(T, x1, y1, x2, y2), get(M, x1, y1, x2, y2), find_rect(x1, y1, x2, y2));
      if (get(T, x1, y1, x2, y2) >= each && get(M, x1, y1, x2, y2) >= each && find_rect(x1, y1, x2, y2) == 0) {
        // puts("USED");
        add_rect(x1, y1, x2, y2);
        cur.push_back(rectangle(x1, y1, x2, y2));
        got += (x2 - x1 + 1) * (y2 - y1 + 1);
      }
    }
    if (got > ans) {
      ans = got;
      answer = cur;
    }
  }
  printf("%d\n", answer.size());
  for (auto it : answer) {
    printf("%d %d %d %d\n", it.x1-1, it.y1-1, it.x2-1, it.y2-1);
  }

  return 0;
}
