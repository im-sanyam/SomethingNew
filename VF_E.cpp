https://codeforces.com/gym/102625/problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1000000007;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m, n;
  cin >> m >> n;
  int it = 0;
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < m; ++i)
  {
    int l, r, x;
    cin >> l >> r >> x;
    v.pb({x, {l - x, r - x}});
  }
  sort(v.begin(), v.end());
  set<int> s;
  vector<int> query;
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    query.pb(x);
    s.insert(x);
  }
  map<int, int> out;
  for (int i = 0; i < m; ++i)
  {
    int val = v[i].first;
    int l = v[i].second.first;
    int r = v[i].second.second;
    auto it1 = s.lower_bound(l);
    auto it2 = s.lower_bound(r);
    vector<int> finish;
    while (it1 != it2)
    {
      out[*it1] = val;
      finish.pb(*it1);
      it1++;
    }
    for (auto x : finish)
      s.erase(x);
  }
  for (int i = 0; i < n; ++i)
  {
    if (out.find(query[i]) != out.end())
      cout << out[query[i]] << endl;
    else
      cout << "-1" << endl;
  }

}
