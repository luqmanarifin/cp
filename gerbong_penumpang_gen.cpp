#include <bits/stdc++.h>

using namespace std;

int kap[] = {52, 64, 106};
string kelas[] = {"Eksekutif", "Bisnis", "Ekonomi"};

int get(int l, int r) {
  return rand() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  for(int i = 1; i <= 707; i++) {
    if(i % 8 == 1 || i % 8 == 2) {
      continue;
    }
    int seed = get(0, 2);
    cout << "(\"" << i << "\", \"" << kap[seed] << "\", \""
    << kelas[seed] << "\")," << endl;
  }
  
  return 0;
}
