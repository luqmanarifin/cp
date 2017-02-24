#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long bit[N];
map<int, int> mp;

long long find(int i) {
  long long ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

void update(int i, long long val) {
  for (; i < N; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

struct item {
  item() {}
  item(int a, int b, int h) : a(a), b(b), h(h) {}
  int a, b, h;
};

bool cmp(item l, item r) {
  if (l.b != r.b) return l.b >= r.b;
  else if (l.a != r.a) return l.a < r.a;
  return l.h > r.h;
}

item a[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> num;
  for (int i = 0; i < n; i++) {
    int A, B, H;
    scanf("%d %d %d", &A, &B, &H);
    a[i] = item(A, B, H);
    num.push_back(A);
    num.push_back(B);
  }
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  for (int i = 0; i < num.size(); i++) mp[num[i]] = i;
  for (int i = 0; i < n; i++) {
    a[i].a = mp[a[i].a];
    a[i].b = mp[a[i].b];
  }
  
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) {
    long long bef = find(a[i].b - 1);
    int j = i;
    while (j + 1 < n && a[j + 1].b == a[j].b) j++;
    long long add = 0;
    for (int k = i; k <= j; k++) {
      add += a[k].h;
    }
    for (int k = i; k <= j; k++) {
      update(a[k].a, bef + add);
    }
    i = j;
  }
  cout << find(N - 1) << endl;
  return 0;
}
