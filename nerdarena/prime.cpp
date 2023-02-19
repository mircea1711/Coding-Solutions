#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;
ifstream cin("prime.in");
ofstream cout("prime.out");
bitset<3000001> ciur;
int main()
{
  ciur[1] = 1;
  for (int i = 4; i <= 3000001; i += 2)
    ciur[i] = 1;
  for (int i = 3; i <= sqrt(3000001); i += 2)
    if (ciur[i] == 0)
    {
      for (int j = i + i; j <= 3000001; j += i)
        ciur[j] = 1;
    }
  int n, x;
  unsigned long long suma = 0;
  cin >> n >> x;
  int copie = n;
  n = n + 1;
  while (ciur[copie] == 1)
    --copie;
  while (x)
  {
    if (ciur[n] == 0)
    {
      suma += n;
      --x;
    }
    ++n;
  }
  cout << copie << "\n"
       << suma;
  return 0;
}