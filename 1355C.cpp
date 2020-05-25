//Link:https://codeforces.com/contest/1355/problem/C  (Refer also Takeuforward for explaination)

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1e9 + 7;
int sum(int num)
{
  if (num == 0)
    return 0;

  return (num * (num + 1)) / 2;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int left = b;
  int ans = 0;
  for (int i = c; i <= d; i++)
  {
    while ((i - left + 1) > b && left <= c)
      left++;

    if (left > c)
      break;

    int x = i - left + 1;
    if (x < a)
      x = a;

    int midrem = c - left;

    int cnt = x - a;

    int l = b - x + 1;

    if (left + cnt <= c)
    {
      int r = l + cnt;
      int extra = midrem - cnt;
      ans += sum(r) - sum(l - 1);
      ans += extra * r;
    }
    else
    {
      int r = l + midrem;
      ans += sum(r) - sum(l - 1);
    }
  }
  cout << ans << endl;
}
