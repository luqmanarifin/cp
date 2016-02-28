#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 5;
const long long sm = 1005;
const long long inf = (long long) 2e18;

vector<long long> km;
vector<pair<long long, long long>> p;
long long beg[N], fin[N];
vector<long long> seg[N];

long long suma[N];
long long sumb[N];

long long id(long long a) {
  return lower_bound(km.begin(), km.end(), a) - km.begin();
}

long long find(int b) {
  long long ret = 0;
  for(auto it : p) {
    if(it.second < b) {
      ret += b - it.second;
    }
    if(b < it.first) {
      ret += it.first - b;
    }
  }
  return ret;
}

pair<long long, long long> debug(int b) {
  long long fs = 0, sc = 0;
  for(auto it : p) {
    assert(it.first <= it.second);
    if(it.second < b) {
      fs += b - it.second;
    }
    if(b < it.first) {
      sc += it.first - b;
    }
  }
  return make_pair(fs, sc);
}

int main() {
  long long pokok = 0;
  long long k, n;
  scanf("%lld %lld", &k, &n);
  while(n--) {
    char sa[3], sb[3];
    long long a, b;
    scanf("%s %lld %s %lld", sa, &a, sb, &b);
    pokok += abs(a - b);
    if(sa[0] != sb[0]) {
      pokok++;
      if(a > b) swap(a, b);
      assert(a <= b);
      p.emplace_back(a, b);
      km.push_back(a);
      km.push_back(b);
    }
  }
  sort(km.begin(), km.end());
  vector<long long> temp;
  for(auto it : km) {
    if(temp.size() && it == temp.back()) {
      continue;
    }
    temp.push_back(it);
  }
  km = temp;
  
  for(auto it : p) {
    long long idi = id(it.first);
    long long idj = id(it.second);
    beg[idi]++;
    fin[idj]++;
    seg[idi].push_back(idj);
  }
  
  long long add = inf;
  long long long_begin = 0;
  long long long_fin = 0;
  long long will_begin = 0;
  long long has_fin = 0;
  for(long long i = (long long) km.size() - 1; i >= 0; i--) {
    if(i + 1 < (long long) km.size()) {
      long_begin += will_begin * (km[i + 1] - km[i]);
    }
    will_begin += beg[i];
  }
  assert(will_begin == (long long) p.size());
  
  for(long long i = 0; i < km.size(); i++) {
    if(i > 0) {
      long_fin += has_fin * (km[i] - km[i - 1]);
      long_begin -= will_begin * (km[i] - km[i - 1]);
    }
    add = min(add, long_begin + long_fin);
    suma[i] = long_fin;
    sumb[i] = long_begin;
    has_fin += fin[i];
    will_begin -= beg[i];
  }

  int l = 0, r = 1000000000;
  while(l + 3 <= r) {
    int leftThird = l + (r - l) / 3;
    int rightThird = r - (r - l) / 3;
    if(find(leftThird) > find(rightThird)) {
      l = leftThird;
    } else {
      r = rightThird;
    }
  }
  long long cuk = inf;
  for(int i = l; i <= r; i++) {
    cuk = min(cuk, find(i));
  }
  assert(cuk <= add);
  add = min(add, cuk);
  
  if(k == 2) {
    for(long long i = 0; i < km.size(); i++) {
      for(long long j = i + 1; j < km.size(); j++) {
        long long mid = 0;
        for(long long l = i + 1; l < j; l++) {
          for(auto it : seg[l]) {
            if(it < j) {
              mid += min(abs(km[i] - km[l]), abs(km[j] - km[it]));
            }
          }
        }
        add = min(add, suma[i] + sumb[j] + mid);
      }
    }
  }
  cout << pokok + (add == inf? 0 : 2 * add) << endl;
  return 0;
}
