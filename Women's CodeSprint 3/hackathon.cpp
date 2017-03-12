#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int BIG = 2e5 + 5;
const int inf = 2e9;

int a[N];
int ada[BIG];
vector<int> num;
map<int, int> mp;
int p[N], q[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ada, 0, sizeof(ada));
    num.clear();
    mp.clear();
    
    int n, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      num.push_back(a[i]);
    }
    scanf("%d", &v);
    for (int i = 0; i < v; i++) {
      scanf("%d %d", p + i, q + i);
      num.push_back(p[i]);
      num.push_back(q[i]);
    }
    sort(num.begin(), num.end());
    num.resize(distance(num.begin(), unique(num.begin(), num.end())));
    for (int i = 0; i < num.size(); i++) {
      mp[num[i]] = i;
    }
    for (int i = 0; i < v; i++) {
      ada[mp[p[i]]]++;
      ada[mp[q[i]] + 1]--;
    }
    for (int i = 1; i < BIG; i++) ada[i] += ada[i - 1];
    int ans = 0;
    for (int i = 0; i < n; i++) if (ada[mp[a[i]]]) ans++;
    cout << ans << endl;
  }
  return 0;
}
