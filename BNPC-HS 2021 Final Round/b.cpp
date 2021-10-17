#include <bits/stdc++.h>

using namespace std;

string a, b;
int n, m;

string zero(int x) {
  string s = "";
  for (int i = 0; i < x; i++) s.push_back('0');
  return s;
}

int get_first(string x) {
  int sz = x.length();
  for (int i = 0; i < sz; i++) {
    if (x[i] == '1') return i;
  }
  assert(0);
}

int get_last(string x) {
  int sz = x.length();
  for (int i = sz - 1; i >= 0; i--) {
    if (x[i] == '1') return sz - 1 - i;
  }
  assert(0);
}

int main() {
  cin >> n >> m >> a >> b;
  if (zero(n) == a && zero(m) == b) {
    puts("0");
    return 0;
  }
  if (zero(m) == b) {
    swap(a, b);
    swap(n, m);
  }
  if (zero(n) == a) {
    int cnt = 0;
    for (int i = 0; i < m; i++) if (b[i] == '1') cnt++;
    cout << n + cnt - 1 << endl;
    return 0;
  }
  int tot = n + m - 1 - min(get_first(a), get_first(b)) - min(get_last(a), get_last(b));
  cout << tot << endl;
  return 0;
}
