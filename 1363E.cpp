//Link: https://codeforces.com/contest/1363/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 998244353;
int a[200005];
int b[200005];
int c[200005];
vector<int> v[200005];
int n, cost = 0;
pair<int, int> dfs(int node, int parent, int minval)
{
  pair<int, int> t = {0, 0};
  if (b[node] != c[node])
  {
    if (b[node])
      t.first++;
    else
      t.second++;
  }
  minval = min(minval, a[node]);
  for (auto it : v[node])
  {
    if (it != parent)
    {
      pair<int, int> c = dfs(it, node, minval);
      t.first += c.first;
      t.second += c.second;
    }
  }
  int combine = min(t.first, t.second);
  t.first -= combine;
  t.second -= combine;
  cost += combine * 2 * minval;
  return t;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n - 1; ++i)
  {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  pair<int, int> p = dfs(1, 0, 1e10);
  if (p.first || p.second)
    cout << "-1" ;
  else
    cout << cost;

}
