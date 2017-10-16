#include <bits/stdc++.h>

using namespace std;

const int N = 30;

bool a1[N], a2[N][N], a3[N][N][N];
char s[1005];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) s[i] -= 'a';
  for (int i = 0; i < n; i++) a1[s[i]] = 1;
  for (int i = 1; i < n; i++) a2[s[i-1]][s[i]] = 1;
  for (int i = 2; i < n; i++) a3[s[i-2]][s[i-1]][s[i]] = 1;
  vector<string> v;
  for (int i = 0; i < 26; i++) {
    string s;
    s.push_back(i + 'a');
    v.push_back(s);
    for (int j = 0; j < 26; j++) {
      s = "";
      s.push_back(i + 'a');
      s.push_back(j + 'a');
      v.push_back(s);
      for (int k = 0; k < 26; k++) {
        s = "";
        s.push_back(i + 'a');
        s.push_back(j + 'a');
        s.push_back(k + 'a');
        v.push_back(s);
      }
    }
  }
  sort(v.begin(), v.end());
  for (auto it : v) {
    if (it.size() == 1) {
      if (!a1[it[0]-'a']) {
        cout << it << endl;
        return 0;
      }
    } else if (it.size() == 2) {
      if (!a2[it[0]-'a'][it[1]-'a']) {
        cout << it << endl;
        return 0;
      }
    } else {
      if (!a3[it[0]-'a'][it[1]-'a'][it[2]-'a']) {
        cout << it << endl;
        return 0;
      }
    }
  }
  assert(0);
  return 0;
}
