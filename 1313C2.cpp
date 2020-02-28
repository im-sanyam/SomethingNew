// Link to the problem - https://codeforces.com/contest/1313/problem/C2

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
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l[n];
  ll r[n];
  ll ls[n];
  ll rs[n];
  stack<pair<ll,ll>> st;
  for (ll i = 0; i < n; i++) {
    while(!st.empty() && (st.top()).first>a[i])
    st.pop();
    if(st.empty())
    ls[i]=-1;
    else
    {
      ls[i]=(st.top()).second;
    }
    st.push({a[i],i});
  }
  for (ll i = 0; i < n; i++) {
    if(ls[i]==-1)
    l[i]=(i+1)*a[i];
    else
    {
      l[i]=l[ls[i]] + (i-ls[i])*a[i];
    }
  }
  while(!st.empty())
  st.pop();
  for (ll i = n-1; i >=0; i--) {
    while(!st.empty() && (st.top()).first>a[i])
    st.pop();
    if(st.empty())
    rs[i]=-1;
    else
    {
      rs[i]=(st.top()).second;
    }
    st.push({a[i],i});
  }
  for (ll i = n-1; i>=0; i--) {
    if(rs[i]==-1)
    r[i]=(n-i)*a[i];
    else
    {
      r[i]=r[rs[i]] + (rs[i]-i)*a[i];
    }
  }
  ll ans = 0;
  ll idx;
  for (ll i = 0; i < n; i++) {
    if(l[i]+r[i]-a[i]>ans)
    {
      ans = l[i]+r[i]-a[i];
      idx = i;
    }
  }

  ll out[n];
  out[idx] = a[idx];
  for (ll j = idx+1; j < n; j++) {
    out[j]= min(a[j],out[j-1]);
  }
  for (ll j = idx-1; j >=0; j--) {
    out[j]= min(a[j],out[j+1]);
  }
  for (ll i = 0; i < n; i++) {
    cout << out[i] << " ";
  }
}
