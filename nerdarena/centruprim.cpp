#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;
ifstream cin("centruprim.in");
ofstream cout("centruprim.out");

int main()
{
  char a[20];
  bool ok = true;
  cin.getline(a, 20);
  int n = 0;
  for (int i = 1; i < strlen(a) - 1; ++i)
  {
    n = n * 10 + a[i] - '0';
  }
  if (n < 2)
    cout << 0;
  else
  {
    for (int i = 2; i <= sqrt(n); ++i)
      if (n % i == 0)
      {
        cout << 0;
        ok = false;
        break;
      }
    if (ok == true)
      cout << 1;
  }
  return 0;
}