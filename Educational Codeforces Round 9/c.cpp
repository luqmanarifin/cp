#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

string str[N];

bool cmp(string a, string b) {
  return a + b < b + a;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str[i];
  }
  sort(str, str + n, cmp);
  for(int i = 0; i < n; i++) printf("%s", str[i].c_str());
  return 0;
}
