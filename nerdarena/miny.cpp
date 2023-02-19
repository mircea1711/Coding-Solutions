
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("miny.in");
ofstream cout("miny.out");
char a[10001];
int prim(int n)
{
  for (int i = 2; i <= sqrt(n); ++i)
    if (n % i == 0)
      return i;
  return n;
}
int main()
{
  int n, o, uc = 1, cnt = 0, max = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> o;
    uc *= o;
    uc %= 100;
    int d = prim(o);
    while (o > 1)
    {
      if (d > max)
        max = d;
      while (o % d == 0)
      {
        ++a[d];
        o /= d;
      }
      d = prim(o);
    }
  }
  int x, i;
  for (i = 2; i <= max; ++i)
    if (a[i])
    {
      x = a[i];
      break;
    }
  for (int j = i; j <= max; ++j)
    if (a[j])
    {
      ++cnt;
      int g = a[j];
      x = __gcd(x, g);
    }
  cout << uc / 10 << "\n"
       << cnt << "\n";
  for (int i = 2; i <= max; ++i)
    if (a[i])
      cout << i << " " << a[i] / x << "\n";
  return 0;
}
