//
//  main.cpp
//  B
//
//  Created by vincent alek on 1/27/18.
//  Copyright © 2018 vincent alek. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
typedef vector< vector<int> > matriks;

int n;
matriks ARR;

void kali(matriks &A, matriks B)
{
    matriks ans = A;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                ans[i][j] += A[i][k]*B[k][j];
                ans[i][j] %= 10;
            }
        }
    }
    A = ans;
}

matriks tambah(matriks A, matriks B)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            A[i][j] = (A[i][j] + B[i][j])%10;
    }
    return A;
}

matriks identity(int x)
{
    matriks ans;
    for(int i = 0; i < x; i++)
    {
        vector<int> temp;
        for(int j = 0; j < x; j++)
        {
            if(i == j) temp.push_back(1);
            else temp.push_back(0);
        }
        ans.push_back(temp);
    }
    cout << ans.size() << "\n";
    return ans;
}

void print(matriks A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            if(j != A.size()-1) cout << A[i][j] << " ";
            else cout << A[i][j] << "\n";
        }
    }
    
}

matriks pangkat(matriks A, int b)
{
    //cout << b << "\n";
    if(b == 0) return identity(n);
    else if(b == 1) return A;
    else if(b%2 == 0)
    {
        matriks temp = pangkat(A,b/2);
        kali(temp,temp);
        return temp;
    }
    else
    {
        matriks temp = pangkat(A,b-1);
        kali(temp, A);
        return temp;
    }
}

matriks F(matriks A, int n)
{
    if(n == 1) return A;
    else if(n&1) return tambah(F(A,n-1),pangkat(A,n));
    else
    {
        matriks temp = F(A,n/2);
        matriks temp2 = temp;
        kali(temp2,pangkat(A,n/2));
        return tambah(temp, temp2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    while(cin >> n >> q)
    {
        ARR.clear();
        if(n == 0 && q == 0) return 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                int x; cin >> x;
                x %= 10;
                temp.pb(x);
            }
            ARR.pb(temp);
        }
        print(F(ARR,q));
        cout << "\n";
    }
    return 0;
}