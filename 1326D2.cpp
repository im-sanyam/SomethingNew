#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll kmp(string s)
{
	vector<int> lps(s.size(), 0);
	for (int i = 1; i < (int)lps.size(); ++i)
	{
		int prev_idx = lps[i - 1];
		while (prev_idx > 0 && s[i] != s[prev_idx])
		{
			prev_idx = lps[prev_idx - 1];
		}
		lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
	}
	return lps[lps.size() - 1];
}

ll largest_pre_pal(string s)
{
	string t = s + "?";
	reverse(s.begin(), s.end());
	t += s;
	return kmp(t);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    ll n= s.length();
    ll i =0;
    ll k = n-1;
    while(i<k)
    {
      if(s[i]==s[k])
      {
        i++;
        k--;
      }
      else
      break;
    }
    if(i==n/2)
    cout << s << endl;
    else
    {
      string out;
      string temp = s.substr(i,n-2*i);
      string temp1 = temp;
      ll pre = largest_pre_pal(temp);
      reverse(temp.begin(),temp.end());
      ll suf = largest_pre_pal(temp);
      if(pre>suf)
      {
        out=temp1.substr(0,pre);
      }
      else
      out=temp.substr(0,suf);
      cout << s.substr(0,i) + out + s.substr(k+1) << endl;
    }
  }
}
