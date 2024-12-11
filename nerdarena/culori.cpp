#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("culori.in");
ofstream fout("culori.out");

int main()
{
  int n, a, fr[99] = {0};

  fin >> n;

  while (n--)
  {
    fin >> a;
    --a;
    fr[a]++;
  }
  for (n = 0; n <= 98; ++n)
  {
    while (fr[n] > 0)
    {
      fout << n + 1 << " ";
      fr[n]--;
    }
  }

  return 0;
}