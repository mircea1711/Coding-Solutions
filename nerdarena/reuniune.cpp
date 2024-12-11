
#include <fstream>
#include <limits.h>
using namespace std;

int main()
{
  ifstream cin("reuniune.in");
  ofstream cout("reuniune.out");
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  if (b2 < a1 || a2 < b1)
    cout << -1 << endl;
  else
  {
    if (a1 > b1)
      a1 = b1;
    if (a2 < b2)
      a2 = b2;
    cout << a1 << " " << a2 << endl;
  }
  return 0;
}