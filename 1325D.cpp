// Link for how - https://www.youtube.com/watch?v=Yb_cHZ67YPM

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll u,v;
  cin >> u >> v;
  if(u>v || u%2!=v%2)
  cout << "-1" << endl;
  else if(u==0 && v==0)
  cout << "0" << endl;
  else if(u==v)
  cout<< 1 << endl << u << endl;
  else
  {
    ll x = v-u;
    x=x/2;
    if(u&x)
    {
      cout << 3 << endl << u << " " << x << " " << x << endl;
    }
    else
    cout << 2 << endl << u+x << " " << x << endl;
  }

}
