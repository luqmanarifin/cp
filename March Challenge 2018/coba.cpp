#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int bit[N];

void add(int i, int val) {
  for (; i < N; i += i & -i) {
    cout << i << endl;
    bit[i] += val;
  }
}

int find(int i) {
  int ret = 0;
  for (; i > 0; i -= i & -i) ret += bit[i];
  return ret;
}  

int main() {
  add(1, 1);
  puts("");
  add(15, 5);
  /*
  for (int i = 1; i <= 5; i++) printf("%d ", find(i)); printf("\n");
  add(3, 3);
  for (int i = 1; i <= 5; i++) printf("%d ", find(i)); printf("\n");
  add(2, 2);
  for (int i = 1; i <= 5; i++) printf("%d ", find(i)); printf("\n");
  add(5, 6);
  for (int i = 1; i <= 5; i++) printf("%d ", find(i)); printf("\n");
  */
  return 0;
}
