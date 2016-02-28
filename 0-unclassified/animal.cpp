#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int prime[] = {13, 17};
const int mod[] = {2000000089, 1000000007};

vector<pair<long long, long long>> ha, hb;
long long power[N][2];
char sa[N * 10], sb[N * 10];
int n;

int digit(int num) {
  int ret = 0;
  while(num > 0) {
    ret++;
    num /= 10;
  }
  return ret;
}

tuple<long long, long long, int> dfs_a(int now) {
  //printf("%d\n", now);
  if(sa[now] != '(') {
    int num = atoi(sa + now);
    ha.emplace_back(power[num][0], power[num][1]);
    return make_tuple(power[num][0], power[num][1], now + digit(num) - 1);
  }
  tuple<long long, long long, int> lef = dfs_a(now + 1);
  tuple<long long, long long, int> rig = dfs_a(get<2>(lef) + 2);
  long long na = (get<0>(lef) + get<0>(rig)) % mod[0];
  long long nb = (get<1>(lef) + get<1>(rig)) % mod[1];
  ha.emplace_back(na, nb);
  return make_tuple(na, nb, get<2>(rig) + 1);
}

tuple<long long, long long, int> dfs_b(int now) {
  if(sb[now] != '(') {
    int num = atoi(sb + now);
    hb.emplace_back(power[num][0], power[num][1]);
    return make_tuple(power[num][0], power[num][1], now + digit(num) - 1);
  }
  tuple<long long, long long, int> lef = dfs_b(now + 1);
  tuple<long long, long long, int> rig = dfs_b(get<2>(lef) + 2);
  long long na = (get<0>(lef) + get<0>(rig)) % mod[0];
  long long nb = (get<1>(lef) + get<1>(rig)) % mod[1];
  hb.emplace_back(na, nb);
  return make_tuple(na, nb, get<2>(rig) + 1);
}

int main() {
  power[0][0] = power[0][1] = 1;
  for(int i = 1; i < N; i++) {
    power[i][0] = power[i - 1][0] * prime[0] % mod[0];
    power[i][1] = power[i - 1][1] * prime[1] % mod[1];
  }
  
  int n;
  scanf("%d %s %s", &n, sa, sb);
  tuple<long long, long long, int> ka = dfs_a(0);
  assert(get<2>(ka) == strlen(sa) - 1);
  tuple<long long, long long, int> kb = dfs_b(0);
  assert(get<2>(kb) == strlen(sb) - 1);
  
  sort(ha.begin(), ha.end());
  sort(hb.begin(), hb.end());
  int ans = 0;
  
  for(auto it : ha) {
    //cout << it.first << ' ' << it.second << endl;;
    if(binary_search(hb.begin(), hb.end(), it)) {
      ans++;
    }
  }
  
  cout << ans << endl;
  /*
  for(int i = 1; i <= n; i++) {
    cout << power[i][0] << ' '  << power[i][1] << endl;
  }
  */
  return 0;
}
