/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

int find(int v) {
  int l = 0, r = 32000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (mid * mid >= v) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;  
}

bool squared(int v) {
  int num = find(v);
  return num * num == v;
}

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> sq, nsq;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (squared(a[i])) {
      sq.push_back(a[i] == 0? 2 : 1);
    } else {
      int num = find(a[i]);
      int val = min(abs(num * num - a[i]), abs((num-1)*(num-1) - a[i]));
      nsq.push_back(val);
    }
  }
  sort(sq.begin(), sq.end());
  sort(nsq.begin(), nsq.end());
  if (sq.size() > nsq.size()) {
    int k = sq.size() - n / 2;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += sq[i];
    }
    cout << ans << endl;
  } else {
    int k = nsq.size() - n / 2;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += nsq[i];
    }
    cout << ans << endl;
  }

  return 0;
}
