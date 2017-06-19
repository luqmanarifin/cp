// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ada[N];
string days[] = {
  "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
};

int solution(string &S) {
  memset(ada, 0, sizeof(ada));

  stringstream ss(S);
  string a, b;
  while (ss >> a) {
    ss >> b;
    b.insert(9, 1, ' ');
    b.insert(8, 1, ' ');
    b.insert(6, 1, ' ');
    b.insert(5, 1, ' ');
    b.insert(3, 1, ' ');
    b.insert(2, 1, ' ');
    istringstream noob(b);
    string junk, k, l, m, n;
    noob >> k >> junk >> l >> junk >> m >> junk >> n;
    int kk = atoi(k.c_str());
    int ll = atoi(l.c_str());
    int mm = atoi(m.c_str());
    int nn = atoi(n.c_str());
    //printf("%s %d %d %d %d\n", a.c_str(), kk, ll, mm, nn);
    int d;
    for (int i = 0; i < 7; i++) if (days[i] == a) {
      d = i;
    }
    int st = d * 24 * 60 + kk * 60 + ll;
    int en = d * 24 * 60 + mm * 60 + nn;
    if (st == en) continue;
    for (int i = st + 1; i <= en; i++) ada[i] = 1;
  }
  int til = 7 * 24 * 60;
  int last = 0;
  int ans = 0;
  for (int i = 1; i <= til; i++) {
    if (ada[i]) {
      last = i;
    } else {
      ans = max(ans, i - last);
    }
  }
  return ans;
}

int main() {
  string str = "Sun 10:00-20:00\nFri 05:00-10:00\nFri 16:30-23:50\nSat 10:00-24:00\nSun 01:00-04:00\nSat 02:00-06:00\nTue 03:30-18:15\nTue 19:00-20:00\nWed 04:25-15:14\nWed 15:14-22:40\nThu 00:00-23:59\nMon 05:00-13:00\nMon 15:00-21:00\n";
  cout << solution(str) << endl;

  string a = "Mon 01:00-23:00\nTue 01:00-23:00\nWed 01:00-23:00\nThu 01:00-23:00\nFri 01:00-23:00\nSat 01:00-23:00\nSun 01:00-21:00\n";
  cout << solution(a) << endl;
  return 0;
}