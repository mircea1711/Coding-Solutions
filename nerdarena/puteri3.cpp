#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ifstream fin("puteri3.in");
  ofstream fout("puteri3.out");
  int sum = 0, j, n, m, a, put;
  fin >> a;
  for (j = 1; j <= a; j++)
  {
    fin >> n >> m;
    n = n % 10;
    if (m == 0)
      put = 0;
    else
    {
      if (n == 0 || n == 1 || n == 5 || n == 6)
        put = 1;
      else if (n == 4 || n == 9)
      {
        if (m % 2 == 0)
          put = 2;
        else
          put = 1;
      }
      else if (m % 4 == 0)
        put = 4;
      else
        put = m % 4;
    }
    sum += pow(n, put);
    sum = sum % 10;
  }
  fout << sum;
}