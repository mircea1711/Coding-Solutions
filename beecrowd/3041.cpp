#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  while (cin >> n && n)
  {
    int r[1001] = {0}, a, d[1001] = {0};
    for (int i = 1; i <= n; ++i)
      cin >> r[i];
    cin >> a;
    sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; ++i)
    {
      int v = min(r[i], a / (n - i + 1));
      d[i] += v;
      for (int j = i; j <= n; ++j)
        r[j] -= v;
      a -= v * (n - i + 1);
    }
    if (a)
      cout << "Impossible\n";
    else
    {
      for (int i = 1; i <= n; ++i)
        d[i] += d[i - 1];
      sort(d + 1, d + n + 1);
      for (int i = n; i; --i)
        cout << d[i] << "\n";
    }
  }
  return 0;
}
