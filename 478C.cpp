// Link: https://codeforces.com/problemset/problem/478/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll M = 1e9 + 7;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<ll> v;
  for (int i = 0; i < 3; ++i)
  {
    ll x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.rbegin(), v.rend());
  ll a = v[0];
  ll b = v[1];
  ll c = v[2];
  if ((b + c) * 2 <= a)
    cout << b + c;
  else
    cout << (a + b + c) / 3;

}
