// https://codeforces.com/contest/1328/problem/E

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v[200005];
bool vis[200005];
ll depth[200005];
ll parent[200005];
ll tin[200005];
ll tout[200005];
ll t =0;
void dfs(ll s)
{
  vis[s]=1;
  tin[s]=t++;
  for (ll i = 0; i < v[s].size(); i++) {
    if(vis[v[s][i]]==0)
    {
      depth[v[s][i]]=depth[s]+1;
      parent[v[s][i]]=s;
      dfs(v[s][i]);
    }
  }
  tout[s]=t++;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin >> n >> m;
  for (ll i = 0; i < n-1; i++) {
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  memset(vis,0,sizeof(vis));
  depth[0]=0;
  parent[0]=-1;
  dfs(0);
  while(m--)
  {
    ll x;
    cin >> x;
    vector<ll> query;
    ll maxi = -1;
    ll u;
    for (ll i = 0; i < x; i++) {
      ll y;
      cin >> y;
      y--;
      query.push_back(y);
      if(maxi < depth[y])
      {
        maxi = depth[y];
        u=y;
      }
    }
    bool flag = true;
    for (ll i = 0; i < query.size(); i++) {
      if(query[i]!=0)
      {
        query[i]=parent[query[i]];
      }
    }
    for (ll i = 0; i < query.size(); i++) {
      if(tin[query[i]]<=tin[u] && tout[u]<=tout[query[i]])
      continue;
      else
      {
        flag =0;
        break;
      }
    }
    if(flag)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;

  }
}
