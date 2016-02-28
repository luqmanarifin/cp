#include <bits/stdc++.h>

using namespace std;

struct c {
  string name;
  int s, p;
};

bool operator<(c a, c b) {
  if(a.s != b.s) return a.s > b.s;
  return a.p < b.p;
}

c a[105];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a[i].name >> a[i].s >> a[i].p;
    }
    sort(a, a + n);
    cout << a[0].name << endl;
  }
  return 0;
}
