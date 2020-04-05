// Link: https://codeforces.com/problemset/problem/1256/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m , d;
  cin >> n >> m >> d;
  ll a[m];
  ll len = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
    len += a[i];
  }
  ll water = n;
  ll it = 0;
  ll ans[n + 1] = {0};
  for (int i = 0; i < m; i++)
  {
    ll extra = a[i] - 1;
    for (int j = d; j >= 1; j--)
    {
      if (water - (j + extra) >= len - a[i])
      {
        water -= (j + extra);
        it += (j);
        len -= a[i];
        ans[it] = i + 1;
        for (int k = 1; k <= extra; ++k)
        {
          ans[it + k] = i + 1;
        }
        it += extra;
        break;
      }
    }
  }
  if (it + d >= n + 1)
    water = 0;
  if (water == 0)
  {
    cout << "YES" << endl;
    for (int i = 1; i < n + 1; ++i)
    {
      cout << ans[i] << " ";
    }
  }
  else
    cout << "NO" << endl;
}
