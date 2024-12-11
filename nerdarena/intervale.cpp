#include <fstream>
#include <vector>
#define NMAX 1000000
using namespace std;
ifstream cin("intervale.in");
ofstream cout("intervale.out");
char nrdiv[NMAX + 5];
vector<int> v[10];
int bsearch1(int i, int p, int u, int key)
{
  int m;
  while (p < u)
  {
    m = (p + u) / 2;
    if (v[i][m] <= key)
      p = m + 1;
    else
      u = m;
  }
  m = (p + u) / 2;
  if (v[i][m] > key)
    --m;
  return m;
}
int bsearch2(int i, int p, int u, int key)
{
  int m;
  while (p < u)
  {
    m = (p + u) / 2;
    if (v[i][m] < key)
      p = m + 1;
    else
      u = m;
  }
  m = (p + u) / 2;
  if (v[i][m] < key)
    ++m;
  return m;
}
int main()
{
  for (int j = 2; j <= NMAX + 5; j += 2)
    nrdiv[j] = 1;
  for (int i = 3; i <= NMAX + 5; i += 2)
    if (nrdiv[i] == 0)
    {
      for (int j = i; j <= NMAX + 5; j += i)
        ++nrdiv[j];
    }
  for (int i = 1; i <= NMAX; ++i)
    v[nrdiv[i]].push_back(i);

  int a, b, k;
  while (cin >> a >> b >> k)
  {
    if (v[k].size())
      cout << bsearch1(k, 0, v[k].size() - 1, b) - bsearch2(k, 0, v[k].size() - 1, a) + 1 << "\n";
    else
      cout << "0\n";
  }
  return 0;
}