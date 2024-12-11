
#include <fstream>

using namespace std;

int main()
{
  ifstream cin("cifre4.in");
  ofstream cout("cifre4.out");
  int n, copie, max2 = 10, max = 0, cnt = 0;
  cin >> n;
  copie = n;
  while (n)
  {
    if (n % 10 > max)
      max = n % 10;
    if (n % 10 == 0 || n % 10 == 1 || n % 10 == 4 || n % 10 == 9)
      cnt++;
    n = n / 10;
  }
  while (copie)
  {
    if (copie % 100 > max2)
      max2 = copie % 100;
    copie = copie / 10;
  }
  cout << max << "\n"
       << cnt << "\n"
       << max2;
  return 0;
}