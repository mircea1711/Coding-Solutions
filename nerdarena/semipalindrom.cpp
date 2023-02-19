#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("semipalindrom.in");
ofstream cout("semipalindrom.out");
int main()
{
  char a[20];
  cin.getline(a, 20);
  int i = 0;
  while (a[i] == a[strlen(a) / 2 + 1])
  {
    ++i;
    if (i > strlen(a) / 2)
      break;
  }
  for (int j = 0; j <= i; ++j)
    cout << a[j];
  return 0;
}

/*
#include <fstream>

using namespace std;

ifstream fin("semipalindrom.in");
ofstream fout("semipalindrom.out");

int nr_cifre(int n)
{
  int p = 0;
  while (n)
  {
    p++;
    n /= 10;
  }
  return p;
}
int n;

int put(int n)
{
  int p = 1;
  while (n)
  {
    p *= 10;
    n--;
  }
  return p;
}

int prima_cifra(int n)
{
  while (n > 9)
    n /= 10;
  return n;
}

int main()
{
  fin >> n;
  if (n % 10 == n)
    fout << n << "\n"; // verific daca n are doar o cifra
  else
  {
    int c = nr_cifre(n);
    int jum = c / 2, rest = c - jum;
    jum = put(jum);
    rest = put(rest);
    if (n % jum == n / rest)
      fout << n % jum << "\n";
    else
      fout << prima_cifra(n);
  }
  return 0;
}
*/