// Link - https://codeforces.com/problemset/problem/371/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll M = 1e9 + 7;
ll bp, sp, cp, r;
bool cost(ll a, ll b, ll c)
{
  ll val = a * bp + b * sp + c * cp;
  if (val <= r)
    return true;
  else
    return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string d;
  cin >> d;
  ll b, s , c;
  cin >> b >> s >> c;
  cin >> bp >> sp >> cp;
  cin >> r;
  ll br = 0;
  ll sr = 0;
  ll cr = 0;
  for (int i = 0; i < d.length(); ++i)
  {
    if (d[i] == 'B')
      br++;
    else if (d[i] == 'S')
      sr++;
    else
      cr++;
  }
  ll low = 0;
  ll high = 1e14;
  while (high - low > 1)
  {
    ll mid = (low + high) / 2;
    ll x1 = max(0LL, mid * br - b);
    ll y1 = max(0LL, mid * sr - s);
    ll z1 = max(0LL, mid * cr - c);
    if (cost(x1, y1, z1))
      low = mid;
    else
      high = mid;
  }
  cout << low;
}
