//Link: https://codeforces.com/contest/1208/problem/B

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
  ll a[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  ll ans = n - 1;
  for (ll i = 0; i < n; ++i)
  {
    map<ll, ll>f;
    bool valid = true;
    for (ll j = 0; j < i; ++j)
    {
      f[a[j]]++;
      if (f[a[j]] > 1)
      {
        valid = false;
        break;
      }
    }
    if (valid)
    {
      ll suffix = n;
      ans = min(ans, suffix - i);
      for (ll j = n - 1; j >= i; j--)
      {
        f[a[j]]++;
        if (f[a[j]] == 1)
        {
          suffix = j;
          ans = min(ans, suffix - i);
        }
        else
          break;
      }
    }
  }
  cout << ans << endl;
}
