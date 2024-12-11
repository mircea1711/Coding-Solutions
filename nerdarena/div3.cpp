#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;

int main()
{
  ifstream fin("div3.in");
  ofstream fout("div3.out");
  bitset<100000> ciur;
  int n;
  long long rad, x;
  ciur[1] = 1;
  fin >> n;
  for (int i = 2; i <= 100000; ++i)
    if (ciur[i] == 0)
      for (int j = i + i; j <= 100000; j = j + i)
        ciur[j] = 1;
  for (int i = 1; i <= n; ++i)
  {
    fin >> x;
    rad = (int)sqrt(x);
    if (rad * rad != x)
      fout << 0 << "\n";
    else
      fout << 1 - ciur[rad] << "\n";
  }
  return 0;
}