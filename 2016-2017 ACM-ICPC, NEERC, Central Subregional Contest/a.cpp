
#include <bits/stdc++.h>

using namespace std;

#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main() {
  open;
  
  int n, k;
  scanf("%d %d", &n, &k);
  n *= 2;
  cout << max(2, (n + k - 1) / k) << endl;

  close;
  return 0;
}
