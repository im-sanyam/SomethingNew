//Link: https://codeforces.com/contest/1343/problem/E

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v[200005];
bool vis[200005];
void bfs(ll s, ll depth[])
{
  memset(vis, 0, sizeof(vis));
  vis[s] = 1;
  queue<ll> q;
  q.push(s);
  depth[s] = 0;
  while (!q.empty())
  {
    ll temp = q.front();
    q.pop();
    for (int i = 0; i < v[temp].size(); ++i)
    {
      if (vis[v[temp][i]] == 0)
      {
        vis[v[temp][i]] = 1;
        depth[v[temp][i]] = depth[temp] + 1;
        q.push(v[temp][i]);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    ll cost[m];
    a--;
    b--;
    c--;
    for (int i = 0; i < n; ++i)
    {
      v[i].clear();
    }
    for (int i = 0; i < m; ++i)
    {
      cin >> cost[i];
    }
    for (int i = 0; i < m; ++i)
    {
      ll x, y;
      cin >> x >> y;
      x--;
      y--;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    ll depth1[n];
    ll depth2[n];
    ll depth3[n];
    bfs(a, depth1);
    bfs(b, depth2);
    bfs(c, depth3);
    sort(cost, cost + m);
    ll sumcost[m + 1];
    sumcost[0] = 0;
    for (int i = 1; i < m + 1; ++i)
    {
      sumcost[i] = sumcost[i - 1] + cost[i - 1];
    }
    ll ans = 1e18;
    for (int i = 0; i < n; ++i)
    {
      if (depth1[i] + depth2[i] + depth3[i] <= m)
      {
        ans = min(ans, sumcost[depth1[i] + depth2[i] + depth3[i]] + sumcost[depth2[i]]);
      }
    }
    cout << ans << endl;
  }
}
