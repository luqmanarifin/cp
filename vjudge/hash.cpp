#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;
vector<int> vec;
const long long MOD = 2e9 + 11;
const long long p1 = 1e9 + 7, p2 = 31;

long long pref1[1000003], pref2[1000003];
long long pwr(long long a, long long b)
{
	if(b == 0) return 1;
	else if(b&1) return (a*pwr(a,b-1))%MOD;
	else
	{
		long long temp = pwr(a,b/2);
		return (temp*temp)%MOD;
	}
}

int main()
{
	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while(t--)
	{
		vec.clear();

		string a, b;
		cin >> a >> b;
		int n = a.length();
		int m = b.length();
		for(int i = 0; i < n; i++)
		{
			pref1[i] = ((long long)(a[i]-'a'+1))*pwr(p1,(n-i));
			pref1[i] %= MOD;
			pref2[i] = ((long long)(a[i]-'a'+1))*pwr(p2,(n-i));
			pref2[i] %= MOD;
		}

		//for(int i = 0; i < n; i++) cout << pref1[i] << " "; cout << "\n";
		//for(int i = 0; i < n; i++) cout << pref2[i] << " "; cout << "\n";

		for(int i = 1; i < n; i++)
		{
			pref1[i] += pref1[i-1]; pref1[i] %= MOD;
			pref2[i] += pref2[i-1]; pref2[i] %= MOD;
		}

		//for(int i = 0; i < n; i++) cout << pref1[i] << " "; cout << "\n";
		//for(int i = 0; i < n; i++) cout << pref2[i] << " "; cout << "\n";
		
		long long sum1 = 0, sum2 = 0;
		for(int i = 0; i < m; i++)
		{
			sum1 += ((long long)(b[i]-'a'+1))*pwr(p1,(m-i));
			sum1 %= MOD;
			sum2 += ((long long)(b[i]-'a'+1))*pwr(p2,(m-i));
		}
		//cout << sum1 << "\n";
		//cout << sum2 << "\n";

		int res = 0;
		for(int i = m-1; i < n; i++)
		{
			long long temp1 = (i == m-1)? pref1[i] : pref1[i] - pref1[i-m]; temp1 = ((temp1%MOD)+MOD)%MOD;
			long long temp2 = (i == m-1)? pref2[i] : pref2[i] - pref2[i-m]; temp2 = ((temp2%MOD)+MOD)%MOD;
			long long kal1 = pwr(p1,(n-1-i));
			long long kal2 = pwr(p2,(n-1-i));
			//cout << i  << " " << sum1 << " " << (sum1*kal1)%MOD << " " << temp1 << "\n";
			//cout << i  << " " << sum2 << " " << (sum2*kal2)%MOD << " " << temp2 << "\n";

			if((sum1*kal1)%MOD == temp1 && (sum2*kal2)%MOD == temp2)
			{
				res++;
				vec.push_back(i-m+1);
			}
		}
		if(res)
		{
			cout << res << "\n";
			for(int i = 0; i < res; i++)
			{
				if(i == res-1)
					cout << vec[i]+1 << "\n";
				else
					cout << vec[i]+1 << " ";
			}
		}
		else
			cout << "Not Found\n";

		if(t != 0)
			cout << "\n";
	}
}

