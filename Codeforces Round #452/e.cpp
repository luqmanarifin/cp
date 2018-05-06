
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int size;
int bef[N], aft[N], len[N], num[N];
set<pair<int, int>> s;    // -panjang, dimana

bool valid(int i) {
  return 1 <= i && i <= size;
}

void remove(int at) {
  int be = bef[at];
  int af = aft[at];
  aft[be] = af;
  bef[af] = be;
  if (valid(be) && valid(af) && num[be] == num[af]) {
    s.erase(make_pair(-len[be], be));
    s.erase(make_pair(-len[af], af));
    len[be] += len[af];
    s.insert(make_pair(-len[be], be));
    remove(af);
  }
}

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j]) j++;
    size++;
    int id = size;
    len[id] = j - i + 1;
    num[id] = a[i];
    s.insert(make_pair(-len[id], id));
    i = j;
  }
  for (int i = 0; i <= size + 1; i++) {
    bef[i] = i - 1;
    aft[i] = i + 1;
  }
  int ans = 0;
  while (!s.empty()) {
    ans++;
    auto it = *(s.begin());
    s.erase(it);
    remove(it.second);
  }
  cout << ans << endl;
  return 0;
}
