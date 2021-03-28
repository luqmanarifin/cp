#include <bits/stdc++.h>

using namespace std;

int ask(int a, int b, int c) {
  printf("%d %d %d\n", a, b, c);
  fflush(stdout);

  int v;
  scanf("%d", &v);
  return v;
}

vector<int> init(int a, int b, int c) {
  vector<int> x;
  int v = ask(a, b, c);
  if (v == a) {
    x.push_back(b);
    x.push_back(a);
    x.push_back(c);
  } else if (v == b) {
    x.push_back(a);
    x.push_back(b);
    x.push_back(c);
  } else {
    x.push_back(a);
    x.push_back(c);
    x.push_back(b);
  }
  return x;
}

vector<int> insert(vector<int> a, int at, int val) {
  vector<int> ret;
  for (int i = 0; i < at; i++) ret.push_back(a[i]);
  ret.push_back(val);
  for (int i = at; i < a.size(); i++) ret.push_back(a[i]);
  return ret;
}

vector<int> solve(vector<int>& a, int l, int r, int x, bool outer) {
  if (l + 1 == r && !outer) {
    return insert(a, r, x);
  }
  if (l + 1 == r) {
    int v = ask(a[l], a[r], x);
    if (v == a[l]) {
      return insert(a, l, x);
    } else if (v == a[r]) {
      return insert(a, r + 1, x);
    } else if (v == x) {
      return insert(a, r, x);
    } else {
      exit(0);
    }
  }
  int mid = rand() % 2? ((l + r) >> 1) : ((l + r + 1) >> 1);
  int v = ask(a[l], a[mid], x);
  if (v == a[l]) {
    assert(outer);
    return insert(a, l, x);
  } else if (v == a[mid]) {
    return solve(a, mid, r, x, outer);
  } else if (v == x) {
    return solve(a, l, mid, x, false);
  } else {
    exit(0);
  }
}

void answer(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  fflush(stdout);

  int v;
  scanf("%d", &v);
  if (v != 1) {
    exit(0);
  }
}

int main() {
  srand(time(NULL));
  int t, n, q;
  scanf("%d %d %d", &t, &n, &q);
  while (t--) {
    vector<int> a, num;
    for (int i = 1; i <= n; i++) num.push_back(i);
    random_shuffle(num.begin(), num.end());

    // printf("urutan: "); for (auto it : num) printf("%d ", it); printf("\n");

    a = init(num[0], num[1], num[2]);
    for (int i = 3; i < num.size(); i++) {
      a = solve(a, 0, a.size() - 1, num[i], true);
    }
    answer(a);
  }
  return 0;
}
