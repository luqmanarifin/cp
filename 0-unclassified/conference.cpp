#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long prime = 4001089;

int n;
int b[N];
int a[N][4];

int get_min() {
  int i = 0, j = 1, k = 0;
  while(i < n && j < n && k < n) {
    if(j == i) {
      j++;
    }
    int ni = (i + k >= n? i + k - n : i + k);
    int nj = (j + k >= n? j + k - n : j + k);
    if(b[ni] < b[nj]) {
      j += k + 1;
      k = 0;
    } else if(b[ni] > b[nj]) {
      i += k + 1;
      k = 0;
    } else {
      k++;
    }
  }
  return i;
}

long long get_hash(int sh) {
  long long v = 0;
  for(int i = 0; i < n; i++) {
    v = v * prime + b[(i + sh) % n];
  }
  return v;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%d", &a[j][i]);
        sum += a[j][i];
      }
    }
    printf("Case %d: ", tt);
    if(sum % n) {
      puts("No");
      continue;
    }
    sum /= n;
    vector<long long> val;
    for(int shift = 0; shift < n; shift++) {
      for(int i = 0; i < n; i++) {
        b[i] = sum - a[i][0] - a[(i + shift) % n][1];
      }
      val.push_back(get_hash(get_min()));
    }
    sort(val.begin(), val.end());
    
    bool found = 0;
    for(int shift = 0; shift < n; shift++) {
      for(int i = 0; i < n; i++) {
        b[i] = a[i][2] + a[(i + shift) % n][3];
      }
      if(binary_search(val.begin(), val.end(), get_hash(get_min()))) {
        puts("Yes");
        found = 1;
        break;
      }
    }
    if(!found) puts("No");
  }
  
  return 0;
}
