
#include <fstream>
#define NMAX 1005
#define enc 105
using namespace std;
ifstream fin("enclave.in");
ofstream fout("enclave.out");
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vecin[enc][enc], viz[NMAX][NMAX];
int n, m, a[NMAX][NMAX], maxi, cnt, cntb, en;
inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && viz[x][y] == 0;
}
void Fill(int x, int y)
{
  viz[x][y] = 1;
  for (int i = 0; i < 4; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (a[x][y] != a[nx][ny])
    {
      if (vecin[a[x][y]][a[nx][ny]] == 0)
      {
        cnt++;
        vecin[a[x][y]][a[nx][ny]] = 1;
      }
      cntb++;
    }
    else if (ok(nx, ny))
      Fill(nx, ny);
  }
}
int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (viz[i][j] == 0)
      {
        cnt = 0;
        cntb = 0;
        Fill(i, j);
        if (vecin[a[i][j]][0] == 0 && cnt == 1)
        {
          en++;
          if (cntb > maxi)
            maxi = cntb;
        }
      }
  fout << en << " " << maxi << "\n";
  return 0;
}