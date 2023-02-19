#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("lascoala.in");
ofstream cout("lascoala.out");
int main()
{
  int a;
  cin >> a;
  int b = sqrt(a);
  if (b * b == a)
    b--;
  cout << a - b * b << "\n";
  int k = b * b;
  for (int i = 1; i <= b; ++i)
  {
    for (int j = 1; j <= b; ++j)
    {
      cout << k << " ";
      k--;
    }
    cout << "\n";
  }
  return 0;
}