
#include <fstream>

using namespace std;

ifstream fin("abc1.in");
ofstream fout("abc1.out");

long long a, b, c;

long long lgput1(long long x, long long y)
{
  long long rez = 1;
  while (y)
  {
    if (y % 2 == 1)
    {
      y--;
      rez = rez * x;
      rez = rez % 4;
    }
    else
    {
      x = x * x;
      y = y / 2;
      x = x % 4;
    }
  }
  if (rez % 4)
    return rez % 4;
  return 4;
}

long long lgput2(long long x, long long y)
{
  long long rez = 1;
  while (y)
  {
    if (y % 2 == 1)
    {
      y--;
      rez = rez * x;
      rez = rez % 10;
    }
    else
    {
      x = x * x;
      y = y / 2;
      x = x % 10;
    }
  }
  return rez % 10;
}

int main()
{
  fin >> a >> b >> c;
  a = a % 10;
  fout << lgput2(a, lgput1(b, c));
  return 0;
}