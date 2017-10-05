/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it,
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
Surely, just as we were that day, like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy,
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light.
Even if you never change, even if you happen to change, you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people.
At that time, I hope we can bring along our irreplaceable families and meet here again.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light.
We run through the passing seasons, seeing each of our many tomorrows,
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

map<tuple<int, long long, long long>, long long> dp;
char s[105];

long long find(int len, long long from, long long to) {
  auto it = make_tuple(len, from, to);
  if (dp.count(it)) return dp[it];
  long long ret = 0;
  for (int i = len - 1; i >= 0; i--) {
    if ((from & (1LL << i)) != (to & (1LL << i))) {
      ret++;
      if (i) {
        long long be = (1LL << (i - 1));
        long long all = (1LL << i) - 1;
        ret += find(i, from & ((1LL << i) - 1), be);
        from &= ~all;
        from |= be;
      }
    }
  }
  return dp[it] = ret;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long mask = 0;
  for (int i = 0; i < n; i++) {
    mask = mask * 2 + s[i] - '0';
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (mask & (1LL << i)) {
      ans++;
      if (i) {
        long long be = (1LL << (i - 1));
        long long all = (1LL << i) - 1;
        ans += find(i, mask & all, be);
        //printf("%lld %lld\n", mask & all, be);
        //printf("lol %lld\n", find(i, mask & all, be));
        mask &= ~all;
        mask |= be;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
