#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 89;
const int N = 3e5 + 5;
string s;
int sa[N], pos[N], lcp[N], tmp[N], gap, len;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < len && b < len) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  len = s.size();
  for(int i = 0; i<len; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + len, cmp_sa);
    for(int i = 1; i<len; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<len; i++) pos[sa[i]] = tmp[i];
    if(tmp[len-1] == len-1) break;
  }
}

long long power[N];

int n;
string str[N];

bool ada(vector<int>& b, string& pattern) {
  for (int it = 1; it < n; it++) {
    int j = 0;
    for (int i = 0; i < str[it].size();) {
      if (pattern[j] == str[it][i]) {
        i++; j++;
      } else if (j > 0) {
        j = b[j - 1];
      } else {
        i++;
      }
      if (j == pattern.size()) {
        return 1;
      }
    }
  }
  return 0;
}

vector<int> precompute(string& pattern) {
  vector<int> a(pattern.size(), 0);
  for (int i = 1; i < pattern.size(); i++) {
    int j = a[i - 1];
    while (j > 0 && pattern[i] != pattern[j]) j = a[j - 1];
    if (pattern[i] == pattern[j]) a[i] = j + 1;
  }
  return a;
}

bool can(int pan, bool print = 0) {
  for (int i = 0; i < len; i++) {
    if (sa[i] + pan > len) continue;
    //printf("panjang %d sa %d\n", pan, sa[i]);
    string o;
    for (int j = 0; j < pan; j++) o.push_back(str[0][sa[i] + j]);
    //cout << o << endl;
    vector<int> kmp = precompute(o);
    //for (auto it : kmp) cout << it << ' '; cout << endl;
    if (!ada(kmp, o)) {
      //cout << o << " ada di kamus" << endl;
      if (print) {
        for (int j = 0; j < pan; j++) {
          printf("%c", str[0][sa[i] + j]);
        }
        printf("\n");
      }
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME;
    assert(power[i]);
  }
  
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    s = str[0];
    build_sa();
    //for (int i = 0; i < len; i++) printf("%d ", sa[i]); printf("\n");
    int l = 1, r = len;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("Case #%d: ", tc);
    if (!can(l)) {
      puts("Impossible");
    } else {
      can(l, 1);
    }
  }
  return 0;
}