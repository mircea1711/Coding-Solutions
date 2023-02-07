#include <iostream>
#include <queue>
#include <string.h>
#define NMAX 1005

using namespace std;

int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1, -2, 0, 2, 0, 2, 2, -2, -2, -1, -1, 1, 1, -2, 2, -2, 2};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0, -2, 0, 2, -1, 1, -1, 1, 2, -2, 2, -2, -2, -2, 2, 2};
int val[] = {2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7};

int viz[NMAX][NMAX];
int c, r, cf, rf, ct, rt, w, c1, c2, r1, r2;

queue<pair<int, int>> q;

inline bool ok(int x, int y)
{
  return x > 0 && y > 0 && x <= c && y <= r;
}

inline bool v(int x, int y)
{
  return x == cf && y == rf;
}

void Lee()
{
  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 24; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        if (viz[nx][ny] == 0 && !v(nx, ny))
        {
          q.push(make_pair(nx, ny));
          viz[nx][ny] = viz[x][y] + val[i];
        }
        else if (viz[nx][ny] > 0 && viz[nx][ny] > viz[x][y] + val[i])
          viz[nx][ny] = viz[x][y] + val[i];
      }
    }
  }
}

void citire()
{
  cin >> c >> r;
  while (c && r)
  {
    memset(viz, 0, sizeof viz);
    cin >> cf >> rf >> ct >> rt;
    cin >> w;
    while (w--)
    {
      cin >> c1 >> r1 >> c2 >> r2;
      for (int i = c1; i <= c2; ++i)
        for (int j = r1; j <= r2; ++j)
          viz[i][j] = -1;
    }
    if (rf == rt && cf == ct)
      cout << "0\n";
    else
    {
      q.push(make_pair(cf, rf));
      Lee();
      if (viz[ct][rt] <= 0)
        cout << "impossible\n";
      else
        cout << viz[ct][rt] << "\n";
    }
    cin >> c >> r;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  citire();
  return 0;
}
