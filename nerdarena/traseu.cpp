#include <fstream>

using namespace std;

ifstream fin("traseu.in");
ofstream fout("traseu.out");

int n, m, a[501][501];

int main()
{
  fin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      fin >> a[i][j];
      a[i][j] += max(a[i - 1][j], a[i][j - 1]);
    }

  fout << a[n][m] << "\n";
  return 0;
}