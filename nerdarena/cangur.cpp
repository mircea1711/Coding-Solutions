#include <fstream>

using namespace std;
ifstream cin("cangur.in");
ofstream cout("cangur.out");
int main()
{
  int n;
  cin >> n;
  unsigned long long suma = 0, copie = 7, nr = 0;
  for (int i = 1; i <= n; ++i)
  {
    nr = nr * 10 + 1;
    suma += 7 * nr;
  }
  cout << suma;
  return 0;
}