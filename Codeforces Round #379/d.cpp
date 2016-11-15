#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> pplus, pmin, px, py;
vector<int> nplus[N], nmin[N], nx[N], ny[N];

int x[N], y[N];
char c[N];

void simplify(vector<int>& a) {
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
}

int get_pplus(int val) {
  return lower_bound(pplus.begin(), pplus.end(), val) - pplus.begin();
}

int get_pmin(int val) {
  return lower_bound(pmin.begin(), pmin.end(), val) - pmin.begin();
}

int get_px(int val) {
  return lower_bound(px.begin(), px.end(), val) - px.begin();
}

int get_py(int val) {
  return lower_bound(py.begin(), py.end(), val) - py.begin();
}

int main() {
  int n, x0, y0;
  scanf("%d %d %d", &n, &x0, &y0);
  for (int i = 0; i < n; i++) {
    scanf(" %c %d %d", c + i, x + i, y + i);
    //printf("%c %d %d\n", c[i], x[i], y[i]);
    pplus.push_back(x[i] + y[i]);
    pmin.push_back(x[i] - y[i]);
    px.push_back(x[i]);
    py.push_back(y[i]);
  }
  //for (auto it : pplus) printf("%d ", it); printf("\n");
  simplify(pplus);
  simplify(pmin);
  simplify(px);
  simplify(py);
  //for (auto it : pplus) printf("%d ", it); printf("\n");
  for (int i = 0; i < n; i++) {
    nplus[lower_bound(pplus.begin(), pplus.end(), x[i] + y[i]) - pplus.begin()].push_back(x[i]);
    nmin[lower_bound(pmin.begin(), pmin.end(), x[i] - y[i]) - pmin.begin()].push_back(x[i]);
    nx[lower_bound(px.begin(), px.end(), x[i]) - px.begin()].push_back(y[i]);
    ny[lower_bound(py.begin(), py.end(), y[i]) - py.begin()].push_back(x[i]);
  }
  for (int i = 0; i < N; i++) {
    sort(nplus[i].begin(), nplus[i].end());
    sort(nmin[i].begin(), nmin[i].end());
    sort(nx[i].begin(), nx[i].end());
    sort(ny[i].begin(), ny[i].end());
  }
  for (int i = 0; i < n; i++) {
    int id_pplus = get_pplus(x[i] + y[i]);
    int id_pmin = get_pmin(x[i] - y[i]);
    int id_px = get_px(x[i]);
    int id_py = get_py(y[i]);
    bool ok_horizontal = false;
    int p = lower_bound(ny[id_py].begin(), ny[id_py].end(), x[i]) - ny[id_py].begin();
    if (p + 1 < ny[id_py].size()) {
      ok_horizontal |= x[i] < ny[id_py][p + 1] && ny[id_py][p + 1] < x0;
    }
    if (p - 1 >= 0) {
      ok_horizontal |= x0 < ny[id_py][p - 1] && ny[id_py][p - 1] < x[i];
    }
    
    bool ok_vertical = false;
    p = lower_bound(nx[id_px].begin(), nx[id_px].end(), y[i]) - nx[id_px].begin();
    if (p + 1 < nx[id_px].size()) {
      ok_vertical |= y[i] < nx[id_px][p + 1] && nx[id_px][p + 1] < y0;
    }
    if (p - 1 >= 0) {
      ok_vertical |= y0 < nx[id_px][p - 1] && nx[id_px][p - 1] < y[i];
    }
    
    bool ok_L = false;
    p = lower_bound(nplus[id_pplus].begin(), nplus[id_pplus].end(), x[i]) - nplus[id_pplus].begin();
    if (p + 1 < nplus[id_pplus].size()) {
      ok_L |= x[i] < nplus[id_pplus][p + 1] && nplus[id_pplus][p + 1] < x0; 
    }
    if (p - 1 >= 0) {
      ok_L |= x0 < nplus[id_pplus][p - 1] && nplus[id_pplus][p - 1] < x[i];
    }
    
    bool ok_R = false;
    p = lower_bound(nmin[id_pmin].begin(), nmin[id_pmin].end(), x[i]) - nmin[id_pmin].begin();
    if (p + 1 < nmin[id_pmin].size()) {
      ok_R |= x[i] < nmin[id_pmin][p + 1] && nmin[id_pmin][p + 1] < x0;
    }
    if (p - 1 >= 0) {
      ok_R |= x0 < nmin[id_pmin][p - 1] && nmin[id_pmin][p - 1] < x[i];
    }
    
    ok_horizontal = !ok_horizontal;
    ok_vertical = !ok_vertical;
    ok_L = !ok_L;
    ok_R = !ok_R;
    if (c[i] == 'R') {
      if (y[i] == y0 && ok_horizontal) {
        puts("YES");
        return 0;
      }
      if (x[i] == x0 && ok_vertical) {
        puts("YES");
        return 0;
      }
    }
    if (c[i] == 'B') {
      if (x[i] + y[i] == x0 + y0 && ok_L) {
        puts("YES");
        return 0;
      }
      if (x[i] - y[i] == x0 - y0 && ok_R) {
        puts("YES");
        return 0;
      }
    }
    if (c[i] == 'Q') {
      if (y[i] == y0 && ok_horizontal) {
        puts("YES");
        return 0;
      }
      if (x[i] == x0 && ok_vertical) {
        puts("YES");
        return 0;
      }
      if (x[i] + y[i] == x0 + y0 && ok_L) {
        puts("YES");
        return 0;
      }
      if (x[i] - y[i] == x0 - y0 && ok_R) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
