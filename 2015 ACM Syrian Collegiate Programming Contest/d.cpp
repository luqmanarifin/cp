#include <bits/stdc++.h>

using namespace std;

char mir[] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y' };
int pos[256];

int main()
{
    long long C = sizeof(mir)/sizeof(mir[0]);
    for (int i = 0; i < C; ++i) {
        pos[mir[i]] = i+1;
    }
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        string s;
        long long K;
        cin >> K >> s;
        int l = s.size()-1;
        long long cur = 0;
        long long p = 1;
        for (; l >= 0; --l) {
            long long gain = (pos['Y']-pos[s[l]])*p;
            if (cur+gain < K) {
                cur += gain;
            }
            else break;
            p *= C;
        }
        if (l > -1) {
            for (int i = 0; i < l; ++i) putchar(s[i]);
            while (l < s.size()) {
                long long dis = (K-cur+p-1)/p;
                assert(pos[s[l]]+dis-1 < C);
                putchar(mir[pos[s[l]]+dis-1]);
                K -= dis*p;
                ++l;
                p /= C;
                cur -= (pos['Y']-pos[s[l]])*p;
            }
        }
        else {
            K -= cur;
            int len = s.size()+1;
            p *= C;
            while (p < K) {
                K -= p;
                p *= C;
                ++len;
            }
            --K;
            vector<int> ans(len);
            int tlen = len;
            while (K) {
                ans[--tlen] = K % C;
                assert(tlen >= 0);
                K /= C;
            }
            for (int i = 0; i < len; ++i) putchar(mir[ans[i]]);
        }
        puts("");
    }
}