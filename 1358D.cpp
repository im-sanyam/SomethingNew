//Link: https://codeforces.com/contest/1358/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1e9 + 7;
int sum(int num)
{
  return (num * (num + 1)) / 2;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x;
  cin >> n >> x;
  int a[2 * n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    a[n + i] = a[i];
  }
  n *= 2;
  vector<int> days(n);
  days[0] = a[0];
  vector<int> hugs(n);
  hugs[0] = sum(a[0]);
  for (int i = 1; i < n; ++i)
  {
    days[i] = days[i - 1] + a[i];
    hugs[i] = hugs[i - 1] + sum(a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    if (days[i] >= x)
    {
      int tempans = 0;
      int remove = days[i] - x;
      int j = lower_bound(days.begin(), days.end(), remove) - days.begin();
      tempans += hugs[i] - hugs[j];
      int useddays = days[i] - days[j];
      int leftdays = x - useddays;
      int lefthugs = sum(a[j]) - sum(a[j] - leftdays);
      tempans += lefthugs;
      ans = max(ans, tempans);
    }
  }
  cout << ans;
}
