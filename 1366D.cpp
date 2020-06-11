//Link: https://codeforces.com/contest/1366/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 998244353;
int MAXN = 10000001;
int spf[10000001];
void sieve()
{
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++)
    spf[i] = i;
  for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < MAXN; i++)
  {
    if (spf[i] == i)
    {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j)
          spf[j] = i;
    }
  }
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  sieve();
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    int x = spf[a[i]];
    int temp = a[i];
    while (temp % x == 0)
    {
      temp = temp / x;
    }
    if (temp == 1)
    {
      v.push_back({ -1, -1});
    }
    else
    {
      v.push_back({x, temp});
    }

  }
  for (auto it : v)
    cout << it.first << " ";
  cout << endl;
  for (auto it : v)
    cout << it.second << " ";

}
