//Link: https://codeforces.com/problemset/problem/415/C

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int M = 1e9 + 7;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int mini = n / 2;
  if (k < mini)
    cout << "-1";
  else if (n == 1)
  {
    if (k)
      cout << "-1";
    else
      cout << "1";
  }
  else
  {
    if (k == 0)
    {
      cout << "-1" ;
      exit(0);
    }
    int val = k / mini;
    vector<int> v(mini, val);
    k = k % mini;
    for (int i = 0; i < k; ++i)
    {
      v[i]++;
    }
    sort(v.begin(), v.end());
    map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < v.size(); ++i)
    {
      map[v[i]]++;
    }
    int start = 1;
    int maxi = 1e9;
    for (auto it : map)
    {
      if (it.first == 1)
      {
        int loop = it.second;
        while (loop)
        {
          ans.push_back(maxi);
          maxi--;
          ans.push_back(maxi);
          maxi--;
          loop--;
        }
      }
      else
      {
        int loop = it.second;
        int st = start * (it.first);
        while (loop--)
        {
          ans.push_back(st);
          st += it.first;
          ans.push_back(st);
          st += it.first;
        }
        st -= it.first;
        st /= it.first;
        start = st;
      }
    }
    for (auto it : ans)
      cout << it << " ";
    if (n % 2)
      cout << maxi - 1;
  }
}
