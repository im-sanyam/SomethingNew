#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1000000007;
vector<int> odd, even;
bool check(int val, int k)
{
  int e = k / 2;
  int o = k - e;
  int cnt = 0;
  for (int i = 0; i < odd.size(); ++i)
  {
    if (odd[i] <= val)
    {
      cnt++;
      i++;
    }
  }
  if (cnt >= o)
    return true;
  cnt = 0;
  for (int i = 0; i < even.size(); ++i)
  {
    if (even[i] <= val)
    {
      cnt++;
      i++;
    }
  }
  if (cnt >= e)
    return true;

  return false;

}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  if (k % 2 == 1)
  {
    for (int i = 0; i < n; ++i)
    {
      odd.pb(a[i]);
    }
    for (int i = 1; i < n - 1; ++i)
    {
      even.pb(a[i]);
    }
  }
  else
  {
    for (int i = 0; i < n - 1; ++i)
    {
      odd.pb(a[i]);
    }
    for (int i = 1; i < n; ++i)
    {
      even.pb(a[i]);
    }
  }
  sort(a, a + n);
  int low = -1;
  int high = n - 1;
  while (high - low > 1)
  {
    int mid = (low + high) / 2;
    if (check(a[mid], k))
      high = mid;
    else
      low = mid;
    // cout << low << " " <<  high << endl;
  }
  cout << a[high];
}
