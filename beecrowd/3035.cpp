#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

map<string, unsigned long long> s;
map<string, vector<pair<string, unsigned long long>>> c;
set<string> af;
string a, b;
unsigned long long n, v;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  while (n--)
  {
    cin >> a >> v;
    s[a] = v;
  }
  while (cin >> a)
  {
    cin >> b >> v;
    af.insert(a);
    c[a].push_back(make_pair(b, v));
  }

  bool ok = false;

  map<string, vector<pair<string, unsigned long long>>>::iterator it;

  while (!ok)
  {
    ok = true;

    for (it = c.begin(); it != c.end(); ++it)
    {
      int v = 0;
      a = it->first;
      if (s.find(a) != s.end())
        v = s[a];
      s[a] = 0;
      for (size_t i = 0; i < c[a].size(); ++i)
      {
        if (s.find(c[a][i].first) != s.end())
          s[a] += s[c[a][i].first] * c[a][i].second;
      }
      if (v != s[a])
        ok = false;
    }
  }

  for (it = c.begin(); it != c.end(); ++it)
    cout << it->first << " " << s[it->first] << "\n";
  return 0;
}
