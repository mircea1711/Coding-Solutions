#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("3numere.in");
ofstream cout("3numere.out");

int main()
{
  int a, b, c;
  unsigned long long nr = 1;
  cin >> a >> b >> c;
  cout << __gcd(__gcd(a, b), c) << "\n";
  int d = 2;
  while (a > 1 || b > 1 || c > 1)
  {
    int p = 0;
    while (a % d == 0)
    {
      ++p;
      a /= d;
    }
    while (b % d == 0)
    {
      ++p;
      b /= d;
    }
    while (c % d == 0)
    {
      ++p;
      c /= d;
    }
    nr *= (p + 1);
    ++d;
  }
  cout << nr;
  return 0;
}