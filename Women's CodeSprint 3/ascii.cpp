#include <bits/stdc++.h>

using namespace std;

string a = "..O..";
string b = "O.o.O";

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a; cout << endl;
    for (int j = 0; j < m; j++) cout << b; cout << endl;
    for (int j = 0; j < m; j++) cout << a; cout << endl; 
  }
  return 0;
}
