#include <bits/stdc++.h>

using namespace std;

// kurang satu
//const long long md = 2147000041;
//const long long prime = 37;

const long long md = 2147000041;
const long long prime = 71;
const int mod = 1000000007;
const int N = 5005;

int bit = 8;
int mask = (1 << bit) - 1;
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int* arr, int n, int shift)
{
    int output[n]; // output array
    int i, count[1 << bit];
    for(i = 0; i <= mask; i++) {
      count[i] = 0;
    }
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]>>shift)&mask ]++;
 
    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i <= mask; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]>>shift)&mask ] - 1] = arr[i];
        count[ (arr[i]>>shift)&mask ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int* arr, int n)
{
    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    for (int shift = 0; shift < 32; shift += bit)
        countSort(arr, n, shift);
}

int comb[N][N];
long long cnt[N];
int has[N][N];
char s[N];
long long ans[N];
long long power[N];
int key[N];
 
int main() {
  /*
  power[0] = 1;
  for(int i = 1; i < N; i++) {
    power[i] = power[i - 1] * prime % md;
  }
  */
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(comb[i][j] >= mod) {
        comb[i][j] -= mod;
      }
    }
    comb[i][0] = comb[i][i] = 1;
  }
  
  int junk, n, q;
  scanf("%d", &junk);
  while(junk--) {
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);
    
    for(int i = 1; i <= n; i++) {
      for(int j = i; j <= n; j++) {
        has[i][j] = (has[i][j - 1] * prime + s[j] - 'a' + 1) % md;
      }
    }
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    
    for(int len = 1; len <= n; len++) {
      int size = 0;
      for(int i = len; i <= n; i++) {
        key[size++] = has[i - len + 1][i];
      }
      radixsort(key, size);
      for(int i = 0; i < size; i++) {
        int j = i;
        while(j + 1 < size && key[j + 1] == key[i]) {
          j++;
        }
        cnt[j - i + 1]++;
        i = j;
      }
    }

    for(int i = 1; i <= n; i++) {
      for(int j = i; j <= n; j++) {
        ans[i] += cnt[j] * comb[j][i];
      }
      ans[i] %= mod;
    }
    
    while(q--) {
      int num;
      scanf("%d", &num);
      if(num > n) {
        printf("0\n");
      } else {
        printf("%lld\n", ans[num]);
      }
    }
  }
  return 0;
}
