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

const int N = 605;

int a[N];
int p, s, n;

int fifo() {
  set<int> st;
  queue<int> q;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (st.count(a[i])) continue;
    if (q.size() == p) {
      ret++;
      st.erase(q.front());
      q.pop();
    }
    st.insert(a[i]);
    q.push(a[i]);
  }
  return ret;
}

int lru() {
  set<int> st;
  deque<int> v;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (st.count(a[i])) {
      v.erase(remove(v.begin(), v.end(), a[i]), v.end());
      v.push_front(a[i]);
    } else {
      if (v.size() == p) {
        ret++;
        st.erase(v.back());
        v.pop_back();
      }
      st.insert(a[i]);
      v.push_front(a[i]);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &p, &s, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      a[i] /= s;
    }
    int ret_fifo = fifo();
    int ret_lru = lru();
    printf("%s %d %d\n", ret_lru < ret_fifo? "yes" : "no", ret_fifo, ret_lru);
  }
  return 0;
}
