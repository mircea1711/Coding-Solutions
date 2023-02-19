
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream fin("ucif.in");
  ofstream fout("ucif.out");
  int sum = 0, j, i, a, put;
  fin >> a;
  for (j = 1; j <= a; j++)
  {
    i = j % 10;
    if (i == 0 || i == 1 || i == 5 || i == 6)
      put = 1;
    else if (i == 4 || i == 9)
    {
      if (j % 2 == 0)
        put = 2;
      else
        put = 1;
    }
    else if (j % 4 == 0)
      put = 4;
    else
      put = j % 4;
    sum += pow(i, put);
    sum = sum % 10;
  }
  fout << sum;
}