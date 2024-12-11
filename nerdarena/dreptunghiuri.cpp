
#include <fstream>
#include <iostream>
#include <algorithm>
#define zeroes(x) (x ^ (x - 1)) & x
using namespace std;

ifstream fin("drept.in");
ofstream fout("drept.out");

const int NMAX = 100001;

int aib[10 * NMAX], n, maxi;
pair<int, int> v[NMAX];

void update(int p, int val)
{
  for (int i = p; i <= 10 * NMAX; i += i & -i)
    aib[i] = max(aib[i], val);
}

int query(int p)
{
  int s = 0;
  for (int i = p; i; i -= i & -i)
    s = max(s, aib[i]);
  return s;
}

inline bool cmp(pair<int, int> x, pair<int, int> y)
{
  if (x.first == y.first)
    return x.second > y.second;
  return x.first < y.first;
}

int main()
{
  fin >> n;

  for (int i = 1; i <= n; ++i)
  {
    fin >> v[i].first >> v[i].second;
    v[i].second++;
    if (v[i].second > maxi)
      maxi = v[i].second;
  }

  sort(v + 1, v + n + 1, cmp);

  int af = 0;

  for (int i = 1; i <= n; ++i)
  {
    int val = query(v[i].second - 1) + 1;
    if (val > af)
      af = val;
    update(v[i].second, val);
  }

  fout << af << "\n";

  return 0;
}