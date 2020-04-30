//Link: https://codeforces.com/contest/1279/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int M = 998244353;
int gcd(int a, int b);
int power(int x, int y, int m);
int modInverse(int a, int m)
{
  int g = gcd(a, m);
  return power(a, m - 2, m);
}

int power(int x, int y, int m)
{
  if (y == 0)
    return 1;
  int p = power(x, y / 2, m) % m;
  p = (p * p) % m;

  return (y % 2 == 0) ? p : (x * p) % m;
}
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int cnt[1000001] = {0};
  vector<vector<int>> v;
  for (int i = 0; i < n; ++i)
  {
    int size;
    cin >> size;
    vector<int> temp;
    for (int i = 0; i < size; ++i)
    {
      int x;
      cin >> x;
      temp.push_back(x);
      cnt[x]++;
    }
    v.push_back(temp);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < v[i].size(); ++j)
    {
      int num = 1;
      int den = 1;
      num *= 1;
      den = ((den % M) * (n % M)) % M;
      num *= 1;
      den = ((den % M) * (v[i].size() % M)) % M;
      num = ((num % M) * (cnt[v[i][j]] % M)) % M;
      den = ((den % M) * (n % M)) % M;;
      int temp = ((num % M) * (modInverse(den, M))) % M;
      ans += temp;
      ans %= M;
    }
  }
  cout << ans;


}
