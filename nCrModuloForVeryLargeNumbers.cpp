/* Link of this problem - https://atcoder.jp/contests/abc156/tasks/abc156_d */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll p = 1e9+7;
ll power(ll x, unsigned ll y)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
ll C(ll N,ll K)
{
	ll x=1,y=1;
	for(ll i=1;i<=K;i++)
	{
		x=x*(N-i+1)%p;
		y=y*i%p;
	}
	return x*power(y,p-2)%p;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,a,b;
  cin >> n >> a >> b;
  ll t1 = (power(2,n) - 1 + p)%p;
  ll t2 = (t1 - C(n,a) + p )%p;
  ll t3 = (t2 - C(n,b) + p )%p;
  cout << t3;
}
