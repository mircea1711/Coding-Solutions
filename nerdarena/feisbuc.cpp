#include <fstream>
#include <queue>
#include <string.h>
#include <limits.h>
#include <bitset>
#pragma warning(disable : 4996)
using namespace std;

class InParser
{
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
    fin = fopen(nume, "r");
    buff = new char[4096];
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

InParser fin("feisbuc.in");
ofstream fout("feisbuc.out");

const int NMAX = 5001;

vector<int> v[NMAX];
int n, m, cnt, nod, diam, t;
int conexa[NMAX];

bitset<NMAX + 3> viz;

void DFS(int x, int d)
{
  viz[x] = 1;

  if (d > diam)
  {
    diam = d;
    nod = x;
  }

  for (size_t i = 0; i < v[x].size(); ++i)
    if (viz[v[x][i]] == 0)
      DFS(v[x][i], d + 1);
}

void solve()
{
  int a, b;

  fin >> n >> m;

  for (int i = 1; i <= m; ++i)
  {
    fin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
    if (viz[i] == 0)
    {
      diam = 0;
      DFS(i, 1);
      conexa[++cnt] = nod;
    }
  fout << cnt << " ";
  viz.reset();
  for (int i = 1; i <= cnt; ++i)
  {
    diam = 0;
    DFS(conexa[i], 1);

    diam >>= 1;

    if (diam > t)
      t = diam;
  }
  fout << t + 1 << "\n";
}
int main()
{
  solve();
  return 0;
}