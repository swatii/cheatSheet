/*
This program is to find nCr%m, where
m: should/must e prime

It exploits

Euclidean algorithm ie gcd(a, b) = gcd(a-b, b): a>b
Bezout's identity: ax + by = d, where gcd(a,b) = d
Fermat's little theorem: a^p-a is an inteeger multiple of p
given p is a prime

a^-1 = a^(m-2) (mod m); only when m is prime

n <=10^6
1<=r<=n

*/

#include<bits/stdc++.h>
#define ll long long

const int Max = 1e6+1;

ll fact[Max], ifact[Max];

using namespace std;
ll mod_exp(ll b, ll exp, ll m)
{
	ll res=1;
	b=b%m;

	while(exp>0)
	{
		if(exp%2==1)
			res = ((res%m)*(b%m))%m;

		exp=exp>>1;

		b = ((b%m)*(b%m))%m;
	}

	return res;
}

ll nCr(ll n, ll r, ll mod)
{
	ll ans = fact[n];
	ans = (ans*ifact[n-r])%mod;
	ans = (ans*ifact[r])%mod;

	return ans;
}

int main()
{
	int mod = 13;
	fact[0] = 1;
	for(int i=1; i<Max; ++i)
		fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;

	ifact[0] = 1;
	for(int i=1; i<Max; ++i)
		ifact[i] = ((ifact[i-1]%mod)*(mod_exp(i, mod-2, mod)))%mod;

	//ll p = mod_exp(4, 13, 497);
	
	ll p = nCr(10, 2, 13);
	cout<<p;
	return 0;
}