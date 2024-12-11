#include <fstream>
using namespace std;
ifstream cin("ecuatie3.in");
ofstream cout("ecuatie3.out");
int main()
{
  unsigned int a, b, x = 1, x1;
  cin >> a >> b;
  x = b / a;
  if (b % a == 0 || x == 1)
    ++x;
  while (x)
  {
    if (x == x1)
      break;
    if ((x * b) % (x * a - b) == 0)
    {
      cout << x << " " << (x * b) / (x * a - b) << "\n";
      x1 = (x * b) / (x * a - b);
    }
    if (x == x1)
      break;
    ++x;
  }
  return 0;
}