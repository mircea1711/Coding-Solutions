#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("compus.in");
ofstream fout("compus.out");

const int maxn = 10005;

int n, e, p, a[maxn], aux, i, j;

int main()
{
  fin >> n >> e >> p;

  for (i = 0; i < n; i++)
  {
    fin >> a[i];
  }

  i = 0;
  while (a[i] != e)
    i++;

  for (j = i + 1; j < n; j++)
    a[j - 1] = a[j];
  n--;
  for (j = n - 1; j >= p; j--)
    a[j + 1] = a[j];
  a[p] = e;
  n++;

  i = 0;
  j = n - 1;
  while (i < j)
  {
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
    i++;
    j--;
  }
  aux = a[0];
  for (i = 1; i < n; i++)
    a[i - 1] = a[i];
  a[n - 1] = aux;

  for (i = 0; i < n; i++)
  {
    fout << a[i] << " ";
  }
  return 0;
}