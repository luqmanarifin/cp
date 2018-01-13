/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it:
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
Surely, just as we were that day... like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy...
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light;
Even if you never change... even if you happen to change... you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people;
At that time, I hope we can bring along our irreplaceable families and meet here again...

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light...
We run through the passing seasons, seeing each of our many tomorrows;
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

string a, b;
int cnt[10];
int ans[20];

// return 1 if can
bool dfs(int now, bool free = 0) {
  if (now == a.size()) return 1;
  if (free) {
    for (int i = now; i < a.size(); i++) {
      for (int j = 9; j >= 0; j--) {
        if (cnt[j]) {
          ans[i] = j;
          cnt[j]--;
          break;
        }
      }
    }
    return 1;
  }
  if (cnt[b[now] - '0']) {
    cnt[b[now] - '0']--;
    ans[now] = b[now] - '0';
    if (dfs(now + 1)) return 1;
    cnt[b[now] - '0']++;
  }
  for (int j = b[now] - '0' - 1; j >= 0; j--) {
    if (cnt[j]) {
      cnt[j]--;
      ans[now] = j;
      if (dfs(now + 1, 1)) return 1;
      cnt[j]++;
    }
  }
  return 0;
}

int main() {
  cin >> a >> b;
  if (a.size() < b.size()) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << a << endl;
    return 0;
  }
  for (int i = 0; i < a.size(); i++) cnt[a[i] - '0']++;
  dfs(0);
  for (int i = 0; i < a.size(); i++) printf("%d", ans[i]);
  return 0;
}
