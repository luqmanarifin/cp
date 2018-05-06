
#include <bits/stdc++.h>

using namespace std;

multiset<int> s;

void insert(int v) {
  s.insert(v);
}

void erase(int v) {
  s.erase(s.find(v));
}

int get() {
  auto it = s.end();
  it--;
  return *it;
}

const int N = 1e5 + 5;

int a[N], d[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    d[i] = a[i] - a[i - 1];
    insert(d[i]);
  }
  int ans = get();
  for (int i = 2; i < n; i++) {
    int sum = d[i] + d[i - 1];
    erase(d[i]);
    erase(d[i - 1]);
    insert(sum / 2);
    insert(sum / 2 + sum % 2);

    ans = min(ans, get());

    insert(d[i]);
    insert(d[i - 1]);
    erase(sum / 2);
    erase(sum / 2 + sum % 2);
  }
  {
    erase(d[1]);
    int best = get();
    erase(best);
    insert(best / 2);
    insert(best / 2 + best % 2);

    ans = min(ans, get());

    insert(d[1]);
    insert(best);
    erase(best / 2);
    erase(best / 2 + best % 2);
  }
  {
    erase(d[n - 1]);
    int best = get();
    erase(best);
    insert(best / 2);
    insert(best / 2 + best % 2);

    ans = min(ans, get());

    insert(d[n - 1]);
    insert(best);
    erase(best / 2);
    erase(best / 2 + best % 2);
  }

  cout << ans << endl;
  return 0;
}
