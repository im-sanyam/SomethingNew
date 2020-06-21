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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string s1 = s;
  string s2 = t;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  if (s1 != s2)
  {
    cout << "-1";
  }
  else
  {
    int a[n] = {0};
    set<int> t1, t2;
    for (int i = 0; i < n; ++i)
    {
      if (s[i] != t[i])
      {
        if (s[i] == '1')
          t1.insert(i);
        else
          t2.insert(i);
      }
    }
    int ans = 0;
    while (t1.size() && t2.size())
    {
      int st1 = *t1.begin();
      int st2 = *t2.begin();
      if (st1 < st2)
      {
        //selecting longest subsequence of 10..
        int f = st1;
        int s = st2;
        t1.erase(f);
        t2.erase(s);
        ans++;
        while (t1.size() && t2.size())
        {
          auto f1 = t1.lower_bound(s);
          auto s2 = t2.lower_bound(*f1);
          if (f1 == t1.end() || s2 == t2.end())
          {
            break;
          }
          else
          {
            s = *s2;
            t1.erase(*f1);
            t2.erase(*s2);
          }
        }
      }
      else
      {
        //rotating longest subsequence of 01..
        int f = st2;
        int s = st1;
        t2.erase(f);
        t1.erase(s);
        ans++;
        while (t1.size() && t2.size())
        {
          auto f1 = t2.lower_bound(s);
          auto s2 = t1.lower_bound(*f1);
          if (f1 == t2.end() || s2 == t1.end())
          {
            break;
          }
          else
          {
            s = *s2;
            t2.erase(*f1);
            t1.erase(*s2);
          }
        }
      }
    }
    cout << ans;
  }
}
