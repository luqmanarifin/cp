#include <bits/stdc++.h>

using namespace std;

const int N = 505;

struct orang {
  orang() {}
  orang(string name, double a, double b, int id) : name(name), a(a), b(b), id(id) {}
  string name;
  double a, b;
  int id;
};

string s[N];
double a[N], b[N];
orang p[N], q[N];

bool cmp_first(orang l, orang r) {
  return l.a < r.a;
}

bool cmp_second(orang l, orang r) {
  return l.b < r.b;
}

int tmp[5];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i] >> b[i];
    p[i] = orang(s[i], a[i], b[i], i);
    q[i] = orang(s[i], a[i], b[i], i);
  }
  sort(p, p + n, cmp_first);
  sort(q, q + n, cmp_second);
  double ans = 2e9;
  for (int i = 0; i < n; i++) {
    double cur = p[i].a;
    int udah = 0;
    for (int j = 0; j < n; j++) {
      if (udah == 3) break;
      if (q[j].id == p[i].id) continue;
      udah++;
      cur += q[j].b;
    }
    if (cur < ans) {
      ans = cur;
      tmp[0] = p[i].id;
      udah = 0;
      for (int j = 0; j < n; j++) {
        if (udah == 3) break;
        if (q[j].id == p[i].id) continue;
        udah++;
        tmp[udah] = q[j].id;
      }
    }
  }
  printf("%.15f\n", ans);
  for (int i = 0; i < 4; i++) printf("%s\n", s[tmp[i]].c_str());

  return 0;
}
