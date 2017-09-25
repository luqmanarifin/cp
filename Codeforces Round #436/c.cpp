#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, f, k;
  scanf("%d %d %d %d", &a, &b, &f, &k);
  vector<int> num;
  num.push_back(f);
  for (int i = 0; i < k - 1; i++) {
    if (i % 2 == 0) {
      num.push_back(2 * (a - f));
    } else {
      num.push_back(2 * f);
    }
  }
  if (k % 2) {
    num.push_back(a - f);
  } else {
    num.push_back(f);
  }
  //for (auto it : num) printf("%d ", it); printf("\n");
  int now = b;
  int ans = 0;
  if (now < num[0]) {
    puts("-1");
    return 0;
  }
  now -= num[0];
  for (int i = 1; i < num.size(); i++) {
    if (b < num[i]) {
      puts("-1");
      return 0;
    }
    //printf("ada %d butuh %d\n", now, num[i]);
    if (now < num[i]) {
      now = b;
      ans++;
      //rintf("isi %d\n", i);
    }
    now -= num[i];
  }
  cout << ans << endl;
  return 0;
}
