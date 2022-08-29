#include <bits/stdc++.h>

using namespace std;

int ask(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

void answer(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

int solve(int a, int b) {
  int u = ask(a, b);
  if (u == 1) {
    return a;
  } else {
    return b;
  }
}

int solve(int a, int b, int c, int d) {
  int u = ask(a, c);
  if (u == 1) {
    return solve(a, d);
  } else if (u == 2) {
    return solve(b, c);
  } else {
    return solve(b, d);
  } 
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<int> s;
    for (int i = 1; i <= (1 << n); i++) {
      s.insert(i);
    }
    while (s.size() != 1) {
      if (s.size() == 2) {
        auto it = s.begin();
        int a = *it;
        it++;
        int b = *it;
        s = {solve(a, b)};
        continue;
      }
      vector<int> tmp;
      set<int> fut;
      for (auto it : s) {
        tmp.push_back(it);
        if (tmp.size() == 4) {
          fut.insert(solve(tmp[0], tmp[1], tmp[2], tmp[3]));
          tmp.clear();
        }
      }
      s = fut;
    }
    answer(*(s.begin()));
  }
  return 0;
}
