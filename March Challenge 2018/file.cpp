#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int last[N], divs[N];

int main() {
  // bikin array - prima terbesar
  memset(last, 0, sizeof(last));
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {   // kalo dia prima
      for (int j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  
  // bikin array - banyak divisor buat tiap bilangan
  divs[1] = 1;
  for (int i = 2; i < N; i++) {           // O(N)
    int primaTerbesar = last[i];
    int pangkat = 0;
    int x = i;        // berapa banyak divisor buat X
    while (x % primaTerbesar == 0) {      // log N
      pangkat++;
      x /= primaTerbesar;
    }
    divs[i] = divs[x] * (pangkat + 1);
  }
  //for (int i = 1; i <= 10; i++) printf("%d: %d\n", i, divs[i]);
  // divs[1] = 1
  // divs[2] = 2
  // divs[6] = 4
  
  // bikin vector, untuk tiap divisor, bilangannya berapa aja
  vector<int> kamus[N];
  for (int i = 1; i < N; i++) {
    kamus[divs[i]].push_back(i);
  }
  // kamus[2] = {2, 3, 5, 7, 11, ...}
  // kamus[3] = {4, 9, 16, ...}
  
  
  // jawab2in pertanyaan
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {              // T kali
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int nikichan = upper_bound(kamus[c].begin(), kamus[c].end(), b)-1 - lower_bound(kamus[c].begin(), kamus[c].end(), a) +1;
    printf("Case #%d: %d\n", tc, nikichan);
  }
  // kompleksitas total = T * O(N) = 10.000 * 1e6 = 1e10
  
  return 0;
}