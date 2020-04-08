// Link: https://codeforces.com/problemset/problem/431/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll M = 1e9 + 7;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, k, d;
  cin >> n >> k >> d;
  ll dp[n + 1][2];
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 1; i <= n; ++i)
  {
    dp[i][0] = 0;
    dp[i][1] = 0;
    for (int j = 1; j <= k; ++j)
    {
      if (i - j < 0)
        break;
      if (j < d)
      {
        dp[i][0] += dp[i - j][0];
        dp[i][0] %= M;
        dp[i][1] += dp[i - j][1];
        dp[i][1] %= M;
      }
      else
      {
        dp[i][1] += dp[i - j][1];
        dp[i][1] %= M;
        dp[i][1] += dp[i - j][0];
        dp[i][1] %= M;
      }
    }
    // cout << dp[i][0] << " " << dp[i][1] << endl;
  }
  cout << dp[n][1];

}
