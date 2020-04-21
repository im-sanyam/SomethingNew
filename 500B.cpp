//Link: https://codeforces.com/problemset/problem/500/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll M = 1e9 + 7;
bool vis[301];
vector<ll> v;
string s[301];
ll a[301];
vector<ll> path;
void dfs(ll t)
{
  vis[t] = 1;
  v.push_back(a[t]);
  path.push_back(t);
  for (int j = 0; j < s[t].length(); ++j)
  {
    if (s[t][j] == '1' && vis[j] == 0)
      dfs(j);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i)
  {
    cin >> s[i];
  }
  memset(vis, 0, sizeof(vis));
  ll ans[n];
  for (int i = 0; i < n; ++i)
  {
    if (vis[i] == 0)
    {
      v.clear();
      path.clear();
      dfs(i);
      sort(v.begin(), v.end());
      sort(path.begin(), path.end());
      for (int i = 0; i < path.size(); ++i)
      {
        ans[path[i]] = v[i];
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    cout << ans[i] << " ";
  }
}
