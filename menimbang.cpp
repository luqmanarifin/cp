#include <bits/stdc++.h>

using namespace std;

char s[105];

int get(int i, int j) {
  return j - i + 1;
}

int go(int i, int j) {
  int n = get(i, j);
  string ret;
  if(n == 1) {
    return i;
  }
  if(n == 2) {
    cout << "TIMBANG 1 " << i << " 1 " << j << endl;
    fflush(stdout);
    cin >> ret;
    if(ret == "KIRI") return i;
    else return j;
  }
  int mid = i + n / 3, rig = i + 2 * (n / 3);
  if(n % 3 == 2) {
    mid++;
    rig += 2;
  }
  cout << "TIMBANG";
  cout << " " << get(i, mid - 1);
  for(int it = i; it <= mid - 1; it++) {
    cout << " " << it;
  }
  cout << " " << get(mid, rig - 1);
  for(int it = mid; it <= rig - 1; it++) {
    cout << " " << it;
  }
  cout << endl;
  fflush(stdout);
  cin >> ret;
  if(ret == "SAMA") return go(rig, j);
  else if(ret == "KIRI") return go(i, mid - 1);
  else return go(mid, rig - 1);
}

int main() {
  int n, k;
  cin >> s >> n >> k;
  cout << "AMBIL " << go(1, n) << endl;
  return 0;
}
