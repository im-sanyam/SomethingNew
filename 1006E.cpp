//Link: https://codeforces.com/contest/1006/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 998244353;
vector<int> v[200005];
bool vis[200005];
int startindex[200005];
int endindex[200005];
vector<int> path;
void dfs(int s)
{
  vis[s] = 1;
  path.pb(s);
  startindex[s] = path.size() - 1;
  for (auto it : v[s])
  {
    if (vis[it] == 0)
      dfs(it);
  }
  endindex[s] = path.size() - 1;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; ++i)
  {
    int x = i;
    int y;
    cin >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  memset(vis, 0, sizeof(vis));
  dfs(1);
  while (q--)
  {
    int node, k;
    cin >> node >> k;
    k--;
    int s = startindex[node];
    int e = endindex[node];
    // cout << s << " " << e << endl;
    if (s + k > e)
      cout << "-1" << endl;
    else
      cout << path[s + k] << endl;
  }
}
