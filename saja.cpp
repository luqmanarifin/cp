#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  int aa = a.length();
  int bb = b.length();
  for(int i = 0; i < aa; i++) {
    string temp = "";
    for(int j = 0; j < aa; j++) {
      if(i != j) temp.push_back(a[j]);
    }
    if(temp == b) {
      puts("Tentu saja bisa!");
      return 0;
    }
  }
  puts("Wah, tidak bisa :(");
  return 0;
}