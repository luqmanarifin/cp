#include <bits/stdc++.h>

using namespace std;

const int BYTE = 16;
const int mod = 1e9 + 7;

int udah[1 << BYTE], add[1 << BYTE][10], to[1 << BYTE][10];

long long dp[10][1 << BYTE][3];
long long cnt[10][1 << BYTE][3];

int bit[20];

long long find(int num) {
  if(num == 0) return 0;
  
  int ori = num;
  vector<int> a;
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  while(num > 0) {
    a.push_back(num % 10);
    num /= 10;
  }
  reverse(a.begin(), a.end());
  for(int i = 1; i < 10; i++) {
    int id = (i < a[0]? 0 : (i == a[0]? 1 : 2));
    dp[0][1 << i][id] = i;
    cnt[0][1 << i][id] = 1;
  }
  for(int i = 0; i + 1 < a.size(); i++) {
    for(int j = 0; j < (1 << BYTE); j++) {
      for(int k = 0; k < 3; k++) {
        if(k == 1) continue;
        if(cnt[i][j][k] == 0) continue;
        for(int d = 0; d < 10; d++) {
          cnt[i + 1][to[j][d]][k] += cnt[i][j][k];
          dp[i + 1][to[j][d]][k] += dp[i][j][k] + add[j][d] * cnt[i][j][k];
        }
      }
      if(cnt[i][j][1] == 0) continue;
      for(int d = 0; d < 10; d++) {
        int id = (d < a[i + 1]? 0 : (d == a[i + 1]? 1 : 2));
        //printf("ke %d id %d jadi %d\n", d, id, to[j][d]);
        cnt[i + 1][to[j][d]][id] += cnt[i][j][1];
        dp[i + 1][to[j][d]][id] += dp[i][j][1] + add[j][d] * cnt[i][j][1];
      }
    }
  }
  long long ans = 0;
  int cur = 0;
  for(int i = 0; i < a.size(); i++) {
    for(int j = 0; j < (1 << BYTE); j++) {
      for(int k = 0; k < 3; k++) {
        if(i + 1 == a.size() && k == 2) continue;
        //if(dp[i][j][k]) printf("%d %d %d %lld\n", i, j, k, dp[i][j][k]);
        ans += dp[i][j][k];
        cur += cnt[i][j][k];
      }
    }
  }
  assert(cur == ori);
  return ans;
}

bool done[16];

int correct(int n) {
  vector<int> a;
  while(n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  reverse(a.begin(), a.end());
  memset(done, 0, sizeof(done));
  int ans = 0;
  for(int i = 0; i < a.size(); i++) {
    int val = 0;
    for(int j = i; j < a.size(); j++) {
      val ^= a[j];
      if(!done[val]) {
        ans += val;
        done[val] = 1;
      }
    }
  }
  return ans;
}

int main() {
  for(int mask = 1; mask < (1 << BYTE); mask++) {
    udah[mask] = mask;
    int sz = 0;
    for(int i = 0; i < 16; i++) {
      if(mask & (1 << i)) {
        bit[sz++] = i;
      }
    }
    for(int i = 0; i < sz; i++) {
      for(int j = i + 1; j < sz; j++) {
        udah[mask] |= (1 << (bit[i] ^ bit[j]));
      }
    }
    for(int i = 0; i < 10; i++) {
      int b = (1 << i);
      for(int j = 0; j < 16; j++) {
        if(mask & (1 << j)) {
          b |= (1 << (i ^ j));
        }
      }
      to[mask][i] = b;
      b = (b ^ (b & udah[mask]));
      for(int j = 0; j < 16; j++) {
        if(b & (1 << j)) {
          add[mask][i] += j;
        }
      }
    }
  }
  /*
  cout << find(121) << endl;
  printf("%d %d %d\n", udah[12], add[12][1], to[12][1]);
  
  for(int i = 1; i <= 1000000; i++) {
    long long benar = correct(i);
    long long mine = find(i) - find(i - 1);
    if(benar != mine) {
      printf("%d wrong! correct %lld, yours %lld\n", i, benar, mine);
      assert(0);
    }
    //printf("%d right\n", i);
  }
  */
  //for(int i = 1; i <= 14; i++) printf("%d: %lld\n", i, find(i) - find(i - 1));
  //cout << find(11) << endl;
  
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%lld\n", (find(r) - find(l - 1)) % mod);
  }
  return 0;
}