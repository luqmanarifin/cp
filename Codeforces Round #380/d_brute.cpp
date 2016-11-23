#include <bits/stdc++.h>

using namespace std;

set<tuple<int, int, int, int>> s;

void solve(int i, int j, int l, int st) {
  if (s.count(make_tuple(i, j, l, st))) return;
  int cnt = j - i + 1;
  if (cnt < l) return;
  s.insert(make_tuple(i, j, l, st));
  if (st == 0) {
    solve(i + l, j, l, st ^ 1);
    solve(i + l + 1, j, l + 1, st ^ 1);
  } else {
    solve(i, j - l, l, st ^ 1);
    solve(i, j - l - 1, l + 1, st ^ 1);
  }
}

int main() {
  solve(2, 4000, 1, 1);
  solve(3, 4000, 2, 1);
  cout << s.size() << endl;

  return 0;
}
