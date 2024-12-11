#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
unsigned long long rl(unsigned long long n, unsigned long long p)
{
  n %= 100019;
  unsigned long long nr = 1;
  while (p > 0)
  {
    if (p % 2 == 1)
    {
      nr = (nr * n) % 100019;
      p--;
    }
    else
    {
      n = (n * n) % 100019;
      p = p / 2;
    }
  }
  return nr;
}
ifstream cin("puteri2.in");
ofstream cout("puteri2.out");

int main()
{
  unsigned long long a[10000], b[10000], sum = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int j = 1; j <= n; ++j)
  {
    cin >> b[j];
    sum += rl(a[j], b[j]);
  }
  cout << sum % 100019;

  return 0;
}