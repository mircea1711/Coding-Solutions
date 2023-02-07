#include <iostream>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
char a[55][55];
char viz[55][55];

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && viz[x][y] == 0 && a[x][y] != 'X';
}

void Fill(int x, int y)
{
  viz[x][y] = 1;
  a[x][y] = 'T';
  for (int i = 0; i < 4; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (ok(nx, ny))
      Fill(nx, ny);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  while (cin >> n >> m && n && m)
  {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
      {
        cin >> a[i][j];
        viz[i][j] = 0;
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i][j] == 'T' && viz[i][j] == 0)
          Fill(i, j);

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= m; ++j)
        cout << a[i][j];
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
