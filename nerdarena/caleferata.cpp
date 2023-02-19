#include <fstream>
using namespace std;
ifstream cin("caleferata.in");
ofstream cout("caleferata.out");
int main()
{
  int x, y, a, b, n, m, p1 = 0, p2 = 0, suma = 10, sgara = 0;
  cin >> a >> b >> m >> n;
  cin >> x >> y;
  if (a == 1)
    sgara += y;
  suma += x + y;
  m -= y;
  if (m == 0)
    p1 = 2;
  else if (m < 0)
  {
    p1 = 1;
    p2 = 2;
  }
  for (int i = 2; i < n; ++i)
  {
    cin >> x >> y;
    if (i == a)
      sgara += y;
    else if (i > a)
    {
      if (i < b)
        sgara += x + y;
    }
    suma += x + y;
    if (m > 0)
    {
      m -= x;
      if (m <= 0)
        p1 = i;
      else
      {
        m -= y;
        if (m == 0)
          p1 = i + 1;
        else if (m < 0)
        {
          p1 = i;
          p2 = i + 1;
        }
      }
    }
  }
  cin >> x;
  suma += x;
  if (m > 0)
  {
    m -= x;
    if (m <= 0)
      p1 = n;
  }
  cout << suma << "\n"
       << sgara << "\n";
  cout << p1;
  if (p2)
    cout << " " << p2;
  return 0;
}