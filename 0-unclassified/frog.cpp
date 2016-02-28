#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

bool dona[N];
bool donb[N];
bool done[N];

int main() {
  long long m, h1, a1, x1, y1, h2, a2, x2, y2;
  scanf("%I64d", &m);
  scanf("%I64d %I64d", &h1, &a1);
  scanf("%I64d %I64d", &x1, &y1);
  scanf("%I64d %I64d", &h2, &a2);
  scanf("%I64d %I64d", &x2, &y2);
  
  long long a, b, c, d;
  
  // ngurusin A
  long long now = h1;
  for(long long i = 0; ; i++) {
    if(dona[now]) {
      puts("-1");
      return 0;
    }
    dona[now] = 1;
    if(now == a1) {
      b = i;
      break;
    }
    //cout << now << endl;
    now = (x1 * now + y1) % m;
  }
  //puts("A cuk");
  memset(dona, 0, sizeof(dona));
  now = (x1 * a1 + y1) % m;
  bool aputar = 1;
  for(long long i = 1; ; i++) {
    if(dona[now]) {
      aputar = 0;
      break;
    }
    dona[now] = 1;
    if(now == a1) {
      a = i;
      break;
    }
    now = (x1 * now + y1) % m;
  }
  //puts("A done");
  
  // ngurusin B
  now = h2;
  for(long long i = 0; ; i++) {
    if(donb[now]) {
      puts("-1");
      return 0;
    }
    donb[now] = 1;
    if(now == a2) {
      d = i;
      break;
    }
    now = (x2 * now + y2) % m;
  }
  now = (x2 * a2 + y2) % m;
  memset(donb, 0, sizeof(donb));
  bool bputar = 1;
  for(long long i = 1; ; i++) {
    if(donb[now]) {
      bputar = 0;
      break;
    }
    donb[now] = 1;
    if(now == a2) {
      c = i;
      break;
    }
    now = (x2 * now + y2) % m;
  }
  
  if(aputar && bputar) {
    for(long long i = 0; i < N; i++) {
      long long cur = a * i + b;
      long long rem = (cur - d) % c;
      if(rem == 0 && cur >= d) {
        cout << cur << endl;
        return 0;
      }
    }
    puts("-1");
  } else if(aputar) {
    tai:;
    if((d - c) % a == 0 && b <= d) {
      cout << d << endl;
    } else {
      puts("-1");
    }
  } else if(bputar) {
    swap(a, c);
    swap(b, d);
    goto tai;
  } else if(b == d) {
    cout << b << endl;
  } else {
    puts("-1");
  }
  return 0;
}
