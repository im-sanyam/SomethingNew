// Link to the problem - https://codeforces.com/problemset/problem/1029/C 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  vector<pair<ll,ll>> v(n),prefix(n),suffix(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(),v.end());
  prefix[0].first = 0;
  prefix[0].second = 1e9;
  suffix[n-1].first = 0;
  suffix[n-1].second = 1e9;
  for (ll i = 1; i < n; i++) {
    prefix[i].first = max(prefix[i-1].first,v[i-1].first);
    prefix[i].second = min(prefix[i-1].second,v[i-1].second);
  }
  for (ll i = n-2; i >=0; i--) {
    suffix[i].first = max(suffix[i+1].first,v[i+1].first);
    suffix[i].second = min(suffix[i+1].second,v[i+1].second);
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll x = max(suffix[i].first,prefix[i].first);
    ll y = min(suffix[i].second,prefix[i].second);
    ans = max(ans, y-x);
  }
  cout << ans;
 
}
