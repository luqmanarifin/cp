#include <bits/stdc++.h>

using namespace std;

const int MAX = 56e6;
const int N = 10;

int n = 5, m = 7, nodes = 35;
int pw[N];

char s[N][N];
bitset<MAX> done;
int a[N][N], x[N], y[N], k;
queue<pair<int, int>> q;

bool bisa_kanan(int i, int j) {
  return j + 1 < m && a[i][j + 1] == 0;
}

bool bisa_kiri(int i, int j) {
  return j - 1 >= 0 && a[i][j - 1] == 0;
}

bool bisa_bawah(int i, int j) {
  return i + 1 < n && a[i + 1][j] == 0;
}

void reset() {
  for (int i = 1; i <= k; i++) a[x[i]][y[i]] = 0;
}

void apply(int h) {
  for (int i = 1; i <= k; i++) {
    int at = h % nodes;
    h /= nodes;
    x[i] = at / m;
    y[i] = at % m;
    a[x[i]][y[i]] = i;
  }
}

int id(int i, int j) {
  return i * m + j;
}

int get() {
  int ret = 0;
  for (int i = 1; i <= k; i++) {
    int at = id(x[i], y[i]);
    ret += at * pw[i - 1];
  }
  return ret;
}

void entry(int v, int ke) {
  if (done[v]) return;
  done[v] = 1;
  q.emplace(v, ke);
}

stack<tuple<int, int, int>> st;

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == -1) printf("7 ");
      else printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void expand(int h, int ke) {
  apply(h);
  //puts("DARI");
  //print();
  for (int t = 1; t <= k; t++) {
    //cout << "iter " << t << endl;
    int i = x[t];
    int j = y[t];
    int ti, tj;

    // ambil kiri
    ti = i; tj = j;
    while (bisa_kiri(ti, tj) && !bisa_bawah(ti, tj)) tj--;
    while (bisa_bawah(ti, tj)) ti++;
    a[i][j] = 0;
    a[ti][tj] = t;
    x[t] = ti;
    y[t] = tj;
    //printf("taruh %d-%d ke %d-%d\n", i, j, ti, tj);
    st.emplace(t, id(i, j), id(ti, tj));
    if (!(i == ti && j == tj)) {
      ti = i; tj = j;
      while (ti - 1 >= 0 && a[ti - 1][j] > 0) {
        st.emplace(a[ti-1][tj], id(ti-1, tj), id(ti, tj));
        x[a[ti-1][tj]] = ti;
        y[a[ti-1][tj]] = tj;
        a[ti][tj] = a[ti-1][tj];
        a[ti-1][tj] = 0;
        ti--;
      }
    }
    //print();
    entry(get(), ke + 1);
    while (!st.empty()) {
      int wow, from, to;
      tie(wow, from, to) = st.top();
      st.pop();
      x[wow] = from / m;
      y[wow] = from % m;
      a[to / m][to % m] = 0;
      a[from / m][from % m] = wow;
    }
    //puts("kiri done");

    // ambil kanan
    ti = i; tj = j;
    while (bisa_kanan(ti, tj) && !bisa_bawah(ti, tj)) tj++;
    while (bisa_bawah(ti, tj)) ti++;
    a[i][j] = 0;
    a[ti][tj] = t;
    x[t] = ti;
    y[t] = tj;
    //printf("taruh %d-%d ke %d-%d\n", i, j, ti, tj);
    st.emplace(t, id(i, j), id(ti, tj));
    if (!(i == ti && j == tj)) {
      ti = i; tj = j;
      while (ti - 1 >= 0 && a[ti - 1][j] > 0) {
        st.emplace(a[ti-1][tj], id(ti-1, tj), id(ti, tj));
        x[a[ti-1][tj]] = ti;
        y[a[ti-1][tj]] = tj;
        a[ti][tj] = a[ti-1][tj];
        a[ti-1][tj] = 0;
        ti--;
      }
    }
    //print();
    entry(get(), ke + 1);
    while (!st.empty()) {
      int wow, from, to;
      tie(wow, from, to) = st.top();
      st.pop();
      x[wow] = from / m;
      y[wow] = from % m;
      a[to / m][to % m] = 0;
      a[from / m][from % m] = wow;
    }
  }
  reset();
}

bool selesai(int h) {
  apply(h);
  bool good = 1;
  int last = -1;
  for (int t = 1; t <= k; t++) {
    if (x[t] != n - 1) good = 0;
    if (last > y[t]) good = 0;
    last = y[t];
  }
  reset();
  return good;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * nodes;

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    done.reset();
    k = 0;

    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          a[i][j] = 0;
        } else if (s[i][j] == '0') {
          a[i][j] = -1;
        } else {
          a[i][j] = s[i][j] - '0';
          x[a[i][j]] = i;
          y[a[i][j]] = j;
          k = max(k, a[i][j]);
        }
      }
    }

    while (!q.empty()) q.pop();
    int start = get();
    reset();
    done[start] = 1;
    q.emplace(start, 0);
    int ans = -1;
    while (!q.empty()) {
      int now, ke;
      tie(now, ke) = q.front();
      //printf("%d %d\n", now, ke);
      q.pop();
      if (selesai(now)) {
        ans = ke;
        break;
      }
      expand(now, ke);
    }
    printf("Case #%d: ", tt);
    if (ans == -1) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
  }

  return 0;
}