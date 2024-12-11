
#include <iostream>
#include <fstream>
#define Nmax 200005
using namespace std;
ifstream fin("rotk.in");
ofstream fout("rotk.out");
int main()
{
  int a[Nmax], i, n1, n2, k1, k2, k3;
  fin >> n1;
  for (i = 1; i <= n1; i++)
    fin >> a[i];
  fin >> k1;
  fin >> n2;
  for (i = n1 + 1; i <= n2 + n1; i++)
    fin >> a[i];
  fin >> k2 >> k3;
  for (i = k1 + 1; i <= n1; i++)
    if (i - k1 > k3)
      fout << a[i] << " ";
  for (i = 1; i <= k1; i++)
    if ((n1 - k1) + i > k3)
      fout << a[i] << " ";
  for (i = n1 + 1 + k2; i <= n1 + n2; i++)
    if (i - k2 > k3)
      fout << a[i] << " ";
  for (i = n1 + 1; i <= n1 + k2; i++)
    if (i + (n2 - k2) > k3)
      fout << a[i] << " ";
  for (i = k1 + 1; i <= n1; i++)
    if (i - k1 <= k3)
      fout << a[i] << " ";
  for (i = 1; i <= k1; i++)
    if ((n1 - k1) + i <= k3)
      fout << a[i] << " ";
  for (i = n1 + 1 + k2; i <= n1 + n2; i++)
    if (i - k2 <= k3)
      fout << a[i] << " ";
  for (i = n1 + 1; i <= n1 + k2; i++)
    if (i + (n2 - k2) <= k3)
      fout << a[i] << " ";
  return 0;
}