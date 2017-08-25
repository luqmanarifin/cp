#include <bits/stdc++.h>

using namespace std;

int get(int n) {
  return (rand() * 32768 + rand()) % n; 
}

pair<int, int> ask(int i) {
  printf("? %d\n", i);
  fflush(stdout);
  int a, b;
  scanf("%d %d", &a, &b);
  return make_pair(a, b);
}

void answer(int v) {
  printf("! %d\n", v);
  fflush(stdout);
  exit(0);
}

const int MAGIC = 1000;
const long long inf = 1e18;

int main() {
  srand(time(0));
  set<int> all;
  int n, start, x;
  scanf("%d %d %d", &n, &start, &x);
  while (all.size() < min(MAGIC, n)) {
    all.insert(get(n) + 1);
  }
  vector<pair<int, int>> coli;
  for (auto it : all) {
    pair<int, int> v = ask(it);
    coli.push_back(v);
  }
  sort(coli.begin(), coli.end());
  int idx = start;
  for (auto it : coli) {
    if (it.first < x) {
      idx = it.second;
    }
  }
  while (idx != -1) {
    pair<int, int> v = ask(idx);
    if (v.first >= x) {
      answer(v.first);
    }
    idx = v.second;
  }
  answer(-1);
  return 0;
}
