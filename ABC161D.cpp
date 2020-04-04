// Link: https://atcoder.jp/contests/abc161/tasks/abc161_d

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll k;
  cin >> k;
  ll cnt = 0;
  vector<string> v;
  queue<string> q;
  for (int i = 1; i < 10; ++i)
  {
    string temp = to_string(i);
    q.push(temp);
  }
  while (!q.empty() && cnt < 100000)
  {
    string t = q.front();
    q.pop();
    v.push_back(t);
    cnt++;
    char last = t.back();
    int num = last - '0';
    if (num >= 1)
    {
      string temp = t;
      temp += (num - 1 + '0');
      q.push(temp);
    }
    string temp = t;
    temp += (num + '0');
    q.push(temp);
    if (num <= 8)
    {
      string temp = t;
      temp += (num + 1 + '0');
      q.push(temp);
    }
  }
  cout << v[k - 1];
}
