#include <bits/stdc++.h>

using namespace std;

int main() {
  int mini = 1000000000;
  int a;
  do {
    cin >> a;
    if(a > 0) mini = min(mini, a);
  } while(a > 0);
  cout << mini << endl;
  return 0;
}