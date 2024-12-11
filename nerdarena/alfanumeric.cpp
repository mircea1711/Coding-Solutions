#include <fstream>
#include <string.h>
using namespace std;

int main()
{
  ifstream fin("alfanumeric.in");
  ofstream fout("alfanumeric.out");
  int n, i, suma = 0;
  char c;
  fin >> n;
  while (fin >> c)
  {
    if (isdigit(c))
      suma += c - 48;
    else if (islower(c))
    {
      c = 'A' + c - 'a';
      fout << c;
    }
    else if (isupper(c))
      fout << c;
  }
  fout << "\n"
       << suma;
  return 0;
}