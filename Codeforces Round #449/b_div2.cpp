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

long long reverse(long long v) {
  vector<int> num;
  while (v) {
    num.push_back(v % 10);
    v /= 10;
  }
  long long ret = 0;
  for (auto it : num) ret = ret * 10 + it;
  return ret;
}

long long dig(int v) {
  if (v < 10) return 1;
  return 1 + dig(v / 10);
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  return a * power(a, b - 1);
}

int main() {
  int k, p;
  scanf("%d %d", &k, &p);
  vector<long long> all;
  for (int i = 1; i <= k; i++) {
    int d = dig(i);
    all.push_back(i * power(10, d) + reverse(i));
  }
  assert(all.size() == k);
  //for (auto it : all) printf("%lld\n", it);
  long long ans = 0;
  for (auto it : all) ans = (ans + it) % p;
  cout << ans << endl;
  return 0;
}
