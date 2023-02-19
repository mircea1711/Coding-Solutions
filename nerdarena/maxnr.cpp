#include <iostream>
#include <fstream>

using namespace std;

int fr[10];

int main()
{
  long n, i, j;
  ifstream fin("maxnr.in");
  ofstream fout("maxnr.out");
  fin >> n;
  while (n > 0)
  {
    fr[n % 10]++;
    n = n / 10;
  }
  for (i = 9; i >= 1; i--)
    if (fr[i] != 0)
    {
      fout << i;
      fr[i]--;
      break;
    }

  for (i = 9; i >= 0; i--)
    for (j = 1; j <= fr[i]; j++)
      fout << i;
  return 0;
}