#include <iostream>
#define ull unsigned long long
using namespace std;

int main()
{
  ull v, n;
  cin >> v >> n;
  v *= n;
  for (ull i = 10; i <= 90; i += 10)
  {
    ull x = (v * i) / 100;
    if (100 * x / v < i)
      x++;
    cout << x;
    if (i != 90)
      cout << " ";
  }
  cout << "\n";
  return 0;
}
