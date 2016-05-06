#include <bits/stdc++.h>

using namespace std;

vector<string> bank[10];
string st;
int maks;

void dfs(int level, int huruf) {
  if(level == maks) {
    bank[maks].push_back(st);
    return;
  }
  for(int i = 0; i < 10; i++) {
    if(abs(i - huruf) > 1) {
      st.push_back(i + 'A');
      dfs(level + 1, i);
      st.pop_back();
    }
  }
}

int main() {
  for(maks = 1; maks <= 6; maks++) {
    dfs(0, -10);
  }
  string a, b;
  while(cin >> a >> b) {
    int la = a.length();
    int lb = b.length();
    if(a.length() > b.length()) {
      puts("0");
      continue;
    }
    if(la == lb && a >= b) {
      puts("0");
      continue;
    }
    if(a.length() == b.length()) {
      int len = a.length();
      int low = upper_bound(bank[len].begin(), bank[len].end(), a) - bank[len].begin();
      int upp = lower_bound(bank[len].begin(), bank[len].end(), b) - bank[len].begin();
      printf("%d\n", upp - low);
    } else {
      int sum = 0;
      for(int i = a.length() + 1; i < b.length(); i++) {
        sum += bank[i].size();
      }
      int low = upper_bound(bank[la].begin(), bank[la].end(), a) - bank[la].begin();
      int upp = lower_bound(bank[lb].begin(), bank[lb].end(), b) - bank[lb].begin();
      sum += (bank[la].size() - low) + upp;
      printf("%d\n", sum);
    }
  }
  return 0;
}