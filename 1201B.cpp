//Link: https://codeforces.com/contest/1201/problem/B

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
  int n;
  cin >> n;
  int a[n];
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  if (sum % 2 == 0 && sum - a[n - 1] >= a[n - 1])
    cout << "YES";
  else
    cout << "NO";
}
