
#include <fstream>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

ifstream fin("drum.in");
ofstream fout("drum.out");

const int NMAX = 100002;

vector<int> v[2][NMAX];

bitset<NMAX> ok;

queue<int> q;

int a, b, n, m, c, ind;
int d[NMAX];

void BFS()
{
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    if (ind == 0)
    {
      for (size_t i = 0; i < v[0][x].size(); ++i)
      {
        int y = v[0][x][i];
        if (d[y] == NMAX)
        {
          d[y] = d[x] + 1;
          q.push(y);
          v[1][y].push_back(x);
        }
        else if (d[x] + 1 == d[y])
          v[1][y].push_back(x);
      }
    }
    else
    {
      for (size_t i = 0; i < v[1][x].size(); ++i)
      {
        int y = v[1][x][i];
        if (ok[y] == 0)
        {
          ok[y] = 1;
          q.push(y);
        }
      }
    }
  }
}

int main()
{
  fin >> n >> m >> c;
  for (int i = 1; i <= m; ++i)
  {
    fin >> a >> b;
    v[0][a].push_back(b);
  }

  fill(d + 1, d + n + 1, NMAX);
  d[1] = 0;

  q.push(1);
  BFS();

  ind = 1;
  q.push(n);
  if (v[1][n].size())
    ok[n] = 1;
  BFS();

  while (c--)
  {
    fin >> a;
    fout << ok[a] << "\n";
  }
  return 0;
}