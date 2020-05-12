//Link: https://codeforces.com/contest/1350/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
int M = 998244353;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }
    bool flag = 0;
    for (int i = 0; i < n; ++i)
    {
      if (a[i] == k)
        flag = 1;
    }
    if (flag == 0)
      cout << "no" << endl;
    else
    {
      if (n == 1)
        cout << "yes" << endl;
      else
      {
        bool f = 0;
        for (int i = 0; i < n - 1; ++i)
        {
          int c = max(a[i], a[i + 1]);
          int b = min(a[i], a[i + 1]);
          if (b >= k)
          {
            f = 1;
            break;
          }
        }
        if (n >= 3)
        {
          for (int i = 1; i < n - 1; ++i)
          {
            if (a[i - 1] > a[i] && a[i] < a[i + 1])
            {
              int c = min(a[i + 1], a[i - 1]);
              if (c >= k)
              {
                f = 1;
                break;
              }
            }
          }
        }
        if (f)
          cout << "yes" << endl;
        else
          cout << "no" << endl;
      }
    }
  }
}
