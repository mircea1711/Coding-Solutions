
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 5 * 1e4 + 2;

vector<pair<unsigned short, unsigned short>> mch[NMAX];
unsigned short t[NMAX], q[NMAX];

class InParser
{
#pragma warning(disable : 4996)
private:
  FILE *fin;
  char *buff;
  int sp;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  InParser(const char *nume)
  {
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
  }
  InParser &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

InParser fin("flota.in");
ofstream fout("flota.out");

int find(int x)
{
  if (x == t[x])
    return x;
  return t[x] = find(t[x]);
}

int main()
{
  int n, m, k, x, y, c;

  fin >> n >> m >> k;

  for (int i = 1; i <= n; ++i)
    t[i] = i;

  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> c;
    mch[c].push_back({x, y});
  }

  int cnt = n;

  n = k;

  for (int i = NMAX - 1; i; --i)
  {
    for (auto j : mch[i])
    {
      x = find(j.first);
      y = find(j.second);
      if (x != y)
      {
        --cnt;

        if (x > y)
          t[x] = y;

        else
          t[y] = x;
      }
    }
    q[i] = cnt;
  }

  for (int i = 1; i <= k; ++i)
  {
    int val;
    fin >> val;
    fout << q[val] << "\n";
  }

  return 0;
}