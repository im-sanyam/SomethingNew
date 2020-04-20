//Link: https://codeforces.com/contest/764/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll M = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> v, diff;
	for (ll i = 0; i < n - 1; ++i)
	{
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		v.push_back({x, y});
	}
	ll c[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}
	ll deg[n] = {0};
	for (int i = 0; i < v.size(); ++i)
	{
		ll u = v[i].first;
		ll w = v[i].second;
		if (c[u] != c[w])
			diff.push_back(v[i]);
	}
	if (diff.size() == 0)
	{
		cout << "YES" << endl;
		cout << "1" << endl;
	}
	else
	{
		for (int i = 0; i < diff.size(); ++i)
		{
			ll x = diff[i].first;
			ll y = diff[i].second;
			deg[x]++;
			deg[y]++;
		}
		for (int i = 0; i < n; ++i)
		{
			if (deg[i] == diff.size())
			{
				cout << "YES" << endl;
				cout << i + 1 << endl;
				exit(0);
			}
		}
		cout << "NO" << endl;
	}

}
