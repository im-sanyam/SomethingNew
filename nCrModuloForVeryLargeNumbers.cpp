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
ll C(int N,int K)
{
	long x=1,y=1;
	for(int i=1;i<=K;i++)
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
  ll t1 = (power(2,n) - 1 - C(n,a) - C(n,b) + p)%p;
  cout << t1;
}
