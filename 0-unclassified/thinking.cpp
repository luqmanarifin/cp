#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
vector<int> a, ok;

int main() {
  int n;
  scanf("%d %s", &n, s);
  assert(n == strlen(s));
  for(int i = 0; i < n; i++) {
    if(i == 0 || s[i] != s[i - 1]) {
      a.push_back(0);
    }
    a.back()++;
  }
  ok.resize(a.size());
  bool nice = 0;
  for(int i = 0; i < a.size(); i++) {
    ok[i] = (a[i] >= 2);
    if(a[i] >= 3) {
      nice = 1;
    }
  }
  int num = 0;
  for(int i = 0; i < a.size(); i++) {
    num += ok[i];
  }
  if(num >= 2 || nice) {
    cout << ok.size() + 2 << endl;
  } else if(num == 1) {
    cout << ok.size() + 1 << endl;
  } else {
    cout << ok.size() << endl;
  }
  return 0;
}
