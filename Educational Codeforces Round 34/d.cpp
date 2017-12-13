/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct bit {
  bit() {
    a.assign(N, 0);
  }
  void add(int i, long long v) {
    for (; i < N; i |= i + 1) {
      a[i] += v;
    }
  }
  long long find(int i) {
    long long ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += a[i];
    }
    return ret;
  }
  vector<long long> a;
};

int a[N];
vector<int> all;

int id(int v) {
  return lower_bound(all.begin(), all.end(), v) - all.begin();
}

int rev(int i) {
  return all.size() - 1 - i;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    for (int j = -1; j <= 1; j++) {
      all.push_back(a[i] + j);
    }
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < n; i++) a[i] = id(a[i]);
  bit sum_low;
  bit sum_upp;
  bit cnt_low;
  bit cnt_upp;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt_low.find(a[i] - 2) * all[a[i]] - sum_low.find(a[i] - 2);
    ans += cnt_upp.find(rev(a[i]) - 2) * all[a[i]] - sum_upp.find(rev(a[i]) - 2);
    
    sum_low.add(a[i], all[a[i]]);
    cnt_low.add(a[i], 1);
    sum_upp.add(rev(a[i]), all[a[i]]);
    cnt_upp.add(rev(a[i]), 1);
  }
  cout << ans << endl;
  return 0;
}
