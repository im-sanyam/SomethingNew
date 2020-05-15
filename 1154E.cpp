//Link: https://codeforces.com/contest/1154/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
int M = 1e9 + 7;
int v[200005][2];
bool vis[200005];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  map<int, int> map;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    map[a[i]] = i;
  }
  for (int i = 0; i < n; ++i)
  {
    if (i == 0)
    {
      v[a[i]][0] = -1;
      if (i + 1 < n)
        v[a[i]][1] = a[i + 1];
      else
        v[a[i]][1] = -1;
    }
    else if (i == n - 1)
    {
      v[a[i]][0] = a[i - 1];
      v[a[i]][1] = -1;
    }
    else
    {
      v[a[i]][0] = a[i - 1];
      v[a[i]][1] = a[i + 1];
    }
  }
  memset(vis, 0, sizeof(vis));
  int c = 0;
  int ans[n];
  for (int i = n; i >= 1; i--)
  {
    if (vis[i] == 0)
    {
      vis[i] = 1;
      ans[map[i]] = c;
      int x = i;
      int t = k;
      while (v[x][1] != -1 && t)
      {
        t--;
        x = v[x][1];
        // cout << x << " ";
        ans[map[x]] = c;
        vis[x] = 1;
      }
      int right = v[x][1];
      x = i;
      t = k;
      while (v[x][0] != -1 && t)
      {
        t--;
        x = v[x][0];
        ans[map[x]] = c;
        vis[x] = 1;
      }
      int left = v[x][0];
      v[left][1] = right;
      v[right][0] = left;
      c = c ^ 1;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    cout << ans[i] + 1;
  }
}
