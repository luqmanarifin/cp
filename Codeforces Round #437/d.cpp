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

const int N = 3e5 + 5;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  multiset<int> plus, minus, unused;
  long long ans = 0;
  for (auto x : a) {
    //printf("before %d\n", x);
    //printf("plus: "); for (auto it : plus) printf("%d ", it); printf("\n");
    //printf("minus: "); for (auto it : minus) printf("%d ", it); printf("\n");
    //printf("unused: "); for (auto it : unused) printf("%d ", it); printf("\n");
    //printf("\n");
    
    if (!unused.empty()) {
      int z = *(unused.begin());
      if (z < x) {
        if (!plus.empty() && *(plus.begin()) < z) {
        } else {
          plus.insert(x);
          minus.insert(z);
          unused.erase(unused.find(z));
          ans += x - z;
          continue;
        }
      }
    }
    if (!plus.empty()) {
      int z = *(plus.begin());
      if (z < x) {
        plus.insert(x);
        plus.erase(plus.find(z));
        unused.insert(z);
        ans += x - z;
        continue;
      }
    }
    unused.insert(x);
  }
  cout << ans << endl;
  return 0;
}
