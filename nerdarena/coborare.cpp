
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

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
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("coborare.in");
std::ofstream fout("coborare.out");

const int NMAX = 1e5 + 2;
const int MOD = 100003;

std::vector<int> g[NMAX];
std::vector<int> dist, viz;
int n, m, v, c, x, y;
std::bitset<NMAX> used, partOfPath;

void BFS()
{
  std::queue<int> q;
  q.push(v);

  dist[v] = 1;

  while (!q.empty())
  {
    int crt = q.front();
    if (crt == c)
      return;
    q.pop();

    for (auto i : g[crt])
    {
      dist[i] += dist[crt];
      if (dist[i] >= MOD)
        dist[i] -= MOD;
      --viz[i];
      if (viz[i] == 0)
        q.push(i);
    }
  }
}

void DFS(int node)
{
  if (node == c)
  {
    partOfPath[node] = 1;
    return;
  }
  bool ok = false;
  used[node] = 1;
  for (auto i : g[node])
  {
    if (used[i] == 0)
      DFS(i);
    ok |= partOfPath[i];
  }
  partOfPath[node] = ok;
}

int main()
{
  fin >> n >> m >> v >> c;

  dist.resize(n + 1);
  viz.resize(n + 1);

  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y;
    g[x].push_back(y);
  }

  DFS(v);

  for (int i = 1; i <= n; ++i)
    if (partOfPath[i])
      for (auto j : g[i])
        ++viz[j];

  BFS();

  fout << dist[c] << "\n";

  fout.close();
  return 0;
}