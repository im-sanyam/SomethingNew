//Link: https://codeforces.com/contest/1111/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 998244353;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, m;
  cin >> n >> k >> m;
  int a[n];
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  int pre[n + 1];
  pre[0] = 0;
  for (int i = 0; i < n; ++i)
  {
    pre[i + 1] = pre[i] + a[i];
  }
  double ans = 0;
  for (int del = 0; del <= min(m, n - 1); del++)
  {
    double base = sum - pre[del];
    double add = min(m - del, k * (n - del));
    base += add;
    double ele = n - del;
    double temp = base / ele;
    ans = max(ans, temp);
  }
  cout << setprecision(10) << ans ;

}
