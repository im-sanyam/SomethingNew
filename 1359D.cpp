//Link: https://codeforces.com/contest/1359/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1e9 + 7;
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
  int ans = 0;
  for (int x = 1; x <= 30; x++)
  {
    int curr = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      if (a[i] <= x)
      {
        curr += a[i];
        sum = max(sum, curr);
        if (curr < 0)
        {
          curr = 0;
        }
      }
      else
      {
        curr = 0;
      }
    }
    ans = max(ans, sum - x);
  }
  cout << ans;
}
