//Link: https://codeforces.com/contest/1341/problem/D
//Link for video: https://youtu.be/0TmuETwVit4

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll M = 1e9 + 7;
ll change[10][7];
ll dp[2001][2001];
ll cost[2000][10];
ll n;
vector<string> num = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
ll compute(ll index, ll sum)
{
  if (index == n)
  {
    if (sum == 0)
      return dp[index][sum] = 1;

    return dp[index][sum] = 0;
  }
  if (dp[index][sum] != -1)
    return dp[index][sum];

  ll maxi = 0;
  for (int i = 9; i >= 0; i--)
  {
    ll cnt = cost[index][i];
    if (cnt <= sum && cnt != -1)
    {
      maxi = max(maxi, compute(index + 1, sum - cnt));
    }
  }
  return dp[index][sum] = maxi;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll k;
  cin >> n >> k;
  string s[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> s[i];
    for (int j = 0; j < 10; ++j)
    {
      for (int k = 0; k < 7; ++k)
      {
        if (s[i][k] == '1' && num[j][k] == '0')
        {
          cost[i][j] = -1;
          break;
        }
        if (s[i][k] == '0' && num[j][k] == '1')
          cost[i][j]++;
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  ll val = compute(0, k);
  string ans = "";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 9; j >= 0; j--)
    {
      ll cnt = cost[i][j];
      if (cnt <= k && cnt != -1 && dp[i + 1][k - cnt] == 1)
      {
        ans += j + '0';
        k -= cnt;
        break;
      }
    }
  }
  if (val)
    cout << ans;
  else
    cout << "-1";
}
