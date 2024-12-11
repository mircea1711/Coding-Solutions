#include <fstream>
#include <bitset>
#include <cmath>
#define NMAX 1000000

using namespace std;
ifstream cin("paisprezece.in");
ofstream cout("paisprezece.out");
bitset<NMAX + 1> ciur;
int main()
{
  for (int i = 4; i <= NMAX; i += 2)
    ciur[i] = 1;
  ;
  for (int i = 3; i <= NMAX; i += 2)
    if (ciur[i] == 0)
    {
      for (int j = i + i; j <= NMAX; j += i)
        ciur[j] = 1;
    }
  int a, b, p = 1, cnt = 0, k;
  cin >> a >> b;
  int i = 2;
  while (pow(i, 6) <= b)
  {
    int putere = i * i * i * i * i * i;
    for (int j = 2; j <= 1000000; j++)
      if (putere * j > b)
        break;
      else if (i != j && putere * j >= a && ciur[j] == 0)
        cnt++;
    i++;
    while (ciur[i] == 1)
      i++;
  }
  i = 2;
  while (pow(i, 13) <= b)
  {
    if (pow(i, 13) >= a)
      ++cnt;
    i++;
    while (ciur[i] == 1)
      i++;
  }
  cout << cnt;
  return 0;
}