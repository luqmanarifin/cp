/*

With our small shoulders next to each others,
we walked all alone
For a mere trivial matter, we burst in laughter
And also gazed for the same dreams
If I listen carefully, 
even now I still could hear
your voice is resounding 
in the middle of 
this orange-colored town

It's so boring, 
when you're nowhere
If I said I felt lonely, 
you'd laugh after me
But countless times, 

I've ensured
all things you left behind won't vanish, 
they'll continue to sparkling beautifully

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

I believe, 
we’ll be the same like those old days
still like innocent children
Run and dash away after the cycle of seasons
Face tomorrows of our own

If I was all alone, I felt uneasy
Sleepless nights, you were always by my side
kept telling me your story

What matters 
will you face from now on?
And also, 
what matters will I face from here?
Secretly, I try to entrust my tears
along with the setting down twilight
in the middle of this orange-colored town

In the midst of millions rays
was born a glimmer of love
Even though you’ve changed
or still the way you’re
You’re still yourself
Nothing to be worried of

It would be nice, 
if someday we’ve been adults
encountered ac
our dearest one,
brought along 
our irreplaceable families
and could meet again here, 
in this place

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

In the midst of millions rays
was born a glimmer of love
Run and dash away after the cycle of seasons
Face tomorrows of our own
Choose dreams of our own

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long s[N], a[N], b[N], need[N];
int n, S;
pair<int, int> v[N];

pair<long long, int> solve(long long A, long long B) {
  //printf("now %lld %lld\n", A, B);
  long long pa = A * S;
  long long pb = B * S;
  // A - B, s, A, B
  for (int i = 0; i < n; i++) {
    v[i] = make_pair(a[i] - b[i], i);
    need[i] = s[i];
  }
  sort(v, v + n);
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    int dif = v[i].first;
    int id = v[i].second;
    if (dif > 0) break;
    long long del = min(pb, need[id]);
    pb -= del;
    need[id] -= del;
    ret += del * b[id];
  }
  for (int i = n - 1; i >= 0; i--) {
    int dif = v[i].first;
    int id = v[i].second;
    if (dif < 0) break;
    long long del = min(pa, need[id]);
    pa -= del;
    need[id] -= del;
    ret += del * a[id];
  }
  long long need_a = 0, need_b = 0;
  for (int i = 0; i < n; i++) {
    int dif = v[i].first;
    int id = v[i].second;

    long long del = min(pb, need[id]);
    pb -= del;
    need[id] -= del;
    ret += del * b[id];
    need_b += del;

    del = min(pa, need[id]);
    pa -= del;
    need[id] -= del;
    ret += del * a[id];
    need_a += del;
  }
  //printf("best %lld\n", ret);
  return {ret, need_a > 0};
}

int main() {
  scanf("%d %d", &n, &S);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", s + i, a + i, b + i);
    tot += s[i];
  }
  long long pizzas = tot / S + (tot % S? 1 : 0);
  //cout << "buy " << pizzas << endl;
  long long l = 0, r = pizzas;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    auto ret = solve(mid, pizzas - mid);
    //printf("%lld %lld\n", lf, rf);
    if (ret.second) {
      r = mid;
    } else {
      l = mid;
    }
  }
  long long ans = -1;
  for (long long i = l; i <= r; i++) {
    ans = max(ans, solve(i, pizzas - i).first);
  }
  cout << ans << endl;
  return 0;
}
