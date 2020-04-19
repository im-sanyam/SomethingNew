// Link: https://codeforces.com/problemset/problem/735/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll M = 1e9 + 7;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  if (n == 2)
    cout << "1";
  else if (n == 3)
    cout << "1";
  else
  {
    if (n % 2 == 0)
      cout << "2";
    else
    {
      bool flag = false;
      for (int i = 2; i * i <= n; ++i)
      {
        if (n % i == 0)
        {
          flag = true;
          break;
        }
      }
      if (flag == false)
      {
        cout << "1";
        exit(0);
      }
      else
      {
        bool flag1 = false;
        for (int i = 2; i * i <= (n - 2); ++i)
        {
          if ((n - 2) % i == 0)
          {
            flag1 = true;
            break;
          }
        }
        if (flag1 == false)
        {
          cout << "2" ;
          exit(0);
        }
        else
        {
          cout << "3";
          exit(0);
        }
      }
    }
  }
}
