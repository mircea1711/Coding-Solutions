
#include <fstream>

using namespace std;

ifstream cin("permcif.in");
ofstream cout("permcif.out");

int cif(int n)
{
  int cnt = 0;
  while (n)
  {
    cnt++;
    n /= 10;
  }
  return cnt;
}

int perm(int n)
{
  int newn = 0, p = 1, cnt = 0;
  while (n >= 10)
  {
    newn += (n % 10) * p;
    p *= 10;
    n /= 10;
    cnt++;
  }
  newn = newn * 10 + n;
  while (cnt < cif(n))
    newn *= 10;
  return newn;
}

int main()
{
  int n, m;
  for (int k = 1; k <= 5; ++k)
  {
    cin >> n >> m;
    int sumn = cif(n);
    bool ok = 0;
    if (n == m)
      cout << "1\n";
    else
    {
      for (int i = 1; i < sumn; i++)
      {
        n = perm(n);
        if (n == m)
        {
          ok = 1;
          break;
        }
      }
      cout << ok << "\n";
    }
  }
  return 0;
}