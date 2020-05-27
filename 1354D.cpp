//Link: https://codeforces.com/contest/1354/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1e9 + 7;
int fen[1000006];
void update(int i, int val)
{
  i++;
  while (i <= 1000006)
  {
    fen[i] += val;
    i += i & (-i);
  }
}

int sum(int i)
{
  i++;
  int s = 0;
  while (i > 0)
  {
    s += fen[i];
    i -= i & (-i);
  }
  return s;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  int a[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    update(a[i], 1);
  }
  while (q--)
  {
    int x;
    cin >> x;
    if (x > 0)
    {
      update(x, 1);
    }
    else
    {
      x *= -1;
      int low = 0;
      int high = n;
      while (low < high)
      {
        int mid = (low + high) / 2;
        int val = sum(mid);

        if (x <= val)
          high = mid;
        else
          low = mid + 1;
      }
      update(low, -1);
    }
  }
  int check = sum(n);
  if (check == 0)
  {
    cout << "0";
  }
  else
  {
    for (int i = 1; i <= n; ++i)
    {
      if (sum(i))
      {
        cout << i;
        break;
      }
    }
  }

}
