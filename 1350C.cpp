//Link: https://codeforces.com/contest/1350/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
int M = 998244353;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  int suf[n];
  suf[n - 1] = a[n - 1];
  int g[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    suf[i] = __gcd(suf[i + 1], a[i]);
  }
  int out = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    g[i] = (a[i] * suf[i + 1]) / (__gcd(a[i], suf[i + 1]));
    out = __gcd(out, g[i]);
  }
  cout << out;
}
