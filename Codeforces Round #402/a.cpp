#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

// a the string, b the substring
bool substr(string& a, string& b) {
  int til[a.size() + 1][26];
  for (int i = 0; i <= a.size(); i++) {
    for (int j = 0; j < 26; j++) {
      til[i][j] = N;
    }
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      til[i][j] = til[i + 1][j];
    }
    til[i][a[i] - 'a'] = i + 1;
  }
  int now = 0;
  for (int i = 0; i < b.size(); i++) {
    if (now > a.size()) break;
    now = til[now][b[i] - 'a'];
  }
  return now <= a.size();
}

int p[N];
char a[N], b[N];
bool bad[N];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
    p[i]--;
  }
  
  string bb = (string) b;
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    memset(bad, 0, sizeof(bad));
    for (int i = 1; i <= mid; i++) {
      bad[p[i]] = 1;
    }
    string str;
    for (int i = 0; i < n; i++) {
      if (bad[i]) continue;
      str.push_back(a[i]);
    }
    if (substr(str, bb)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
