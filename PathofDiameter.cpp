#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll ch;
vector<ll> v[200000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  for (ll i = 0; i < n-1; i++) {
    ll x,y;
    cin >> x >> y ;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  bool vis[n];
  ll dis[n];
  memset(dis,0, sizeof(dis));
  memset(vis,0, sizeof(vis));

  queue<ll> q;
  q.push(0);
  dis[0]=0;
  vis[0]=1;
  while(!q.empty())
  {
    ll temp = q.front();
    q.pop();
    for (ll i = 0; i < v[temp].size(); i++) {
      if(vis[v[temp][i]]==0)
      {
        vis[(v[temp][i])]=1;
        dis[v[temp][i]]= dis[temp]+1;
        q.push(v[temp][i]);
      }
    }
  }
  ll maxi =0;
  ll index;
  for (ll i = 0; i < n; i++) {
    if(dis[i]>maxi)
    {
      maxi=dis[i];
      index = i;
    }
  }

  ll dis2[n];
  memset(dis2,0, sizeof(dis));
  memset(vis,0, sizeof(vis));
  q.push(index);
  dis2[index]=0;
  vis[index]=1;
  ll parent[n];
  for (ll i = 0; i < n; i++) {
    parent[i]=-1;
  }
  while(!q.empty())
  {
    ll temp = q.front();
    q.pop();
    for (ll i = 0; i < v[temp].size(); i++) {
      if(vis[v[temp][i]]==0)
      {
        vis[(v[temp][i])]=1;
        dis2[v[temp][i]]= dis2[temp]+1;
        parent[v[temp][i]]=temp;
        q.push(v[temp][i]);
      }
    }
  }
  maxi =0;
  ll index2;
  for (ll i = 0; i < n; i++) {
    if(dis2[i]>maxi)
    {
      maxi=dis2[i];
      index2 = i;
    }
  }
  if(maxi==n-1)
  {
    cout << maxi << endl;
    cout << index+1 << " " << index2+1 << " " << parent[index2]+1;
  }
  else
  {
    ll x = index2;
    ll path[n]={0};
    while(parent[x]!=-1)
    {
      path[x]=1;
      x=parent[x];
      path[x]=1;
    }

    memset(dis,0, sizeof(dis));
    memset(vis,0, sizeof(vis));

    queue<ll> q;
    for (ll i = 0; i < n; i++) {
      if(path[i]==1)
      {
        q.push(i);
        dis[i]=0;
        vis[i]=1;
      }
    }
    while(!q.empty())
    {
      ll temp = q.front();
      q.pop();
      for (ll i = 0; i < v[temp].size(); i++) {
        if(vis[v[temp][i]]==0)
        {
          vis[(v[temp][i])]=1;
          dis[v[temp][i]]= dis[temp]+1;
          q.push(v[temp][i]);
        }
      }
    }
    ll maxi2 =0;
    ll index3;
    for (ll i = 0; i < n; i++) {
      if(dis[i]>maxi2)
      {
        maxi2=dis[i];
        index3 = i;
      }
    }
    cout << maxi + maxi2 << endl;
    cout << index+1 << " " << index2 +1 << " " << index3+1;
  }



}
