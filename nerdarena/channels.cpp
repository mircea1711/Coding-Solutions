
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 1e5 + 1;

struct muchie
{
  pair<unsigned short, unsigned short> p;
  unsigned short val;
};

muchie mch[NMAX];
unsigned short t[NMAX];

ifstream fin("channels.in");
ofstream fout("channels.out");

int find(int x)
{
  if (x == t[x])
    return x;
  return t[x] = find(t[x]);
}

inline bool cmp(pair<unsigned short, unsigned short> a, pair<unsigned short, unsigned short> b)
{
  return a.second < b.second;
}

int main()
{
  int n, m, k, x, y, c;

  fin >> n >> m;

  for (int i = 1; i <= m; ++i)
  {
    fin >> mch[i].p.first >> mch[i].p.second >> mch[i].val;
    t[mch[i].p.first] = mch[i].p.first;
    t[mch[i].p.second] = mch[i].p.second;
  }

  fin >> k;

  for (int i = 1; i <= m; ++i)
  {
    if (mch[i].val >= k)
    {
      x = find(mch[i].p.first);
      y = find(mch[i].p.second);
      if (x != y)
      {
        --n;
        if (x > y)
          t[x] = y;
        else
          t[y] = x;
      }
    }
  }

  fout << n - 1 << "\n";

  return 0;
}