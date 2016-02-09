#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], tmp[N];
int power[N], n, k;
set<long long> ada;

long long get() {
  long long ret = 0;
  for(int i = 0; i < n; i++) {
    ret += power[n - 1 - i] * a[i];
  }
  return ret;
}

void flush(long long val) {
  for(int i = 0; i < n; i++) {
    a[i] = val / power[n - 1 - i];
    val = val % power[n - 1 - i];
  }
}

void print() {
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d %d", &n, &k);
  
  power[0] = 1;
  for(int i = 1; i < N; i++) {
    power[i] = power[i - 1] * n;
  }  

  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  ada.insert(get());
  
  while(1) {
    set<long long> t;
    for(auto it : ada) {
      flush(it);
      
      for(int i = 0; i + k <= n; i++) {
        int temp = a[i + k - 1];
        for(int j = i + k - 1; j > i; j--) {
          a[j] = a[j - 1];
        }
        a[i] = temp;
        
        long long val = get();
        if(!ada.count(val) && !t.count(val)) {
          t.insert(val);
        }
        
        temp = a[i];
        for(int j = i; j < i + k - 1; j++) {
          a[j] = a[j + 1];
        }
        a[i + k - 1] = temp;
      }
    }
    if(t.empty()) break;
    for(auto it : t) ada.insert(it);
  }
  for(auto it : ada) {
    flush(it);
    print();
  }
  
  return 0;
}
