#include <iostream>
#include <set>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    set<pair<int, int>> s;
    int n, m, a, b;
    cin >> n;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
      cin >> a >> b;
      s.insert(make_pair(a, b));
      s.insert(make_pair(b, a));
    }
    cout << s.size() << "\n";
  }
  return 0;
}
