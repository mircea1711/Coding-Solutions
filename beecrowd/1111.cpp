#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>> q;
string a[11][11];
int lee[11][11];
int n;
char v;
int x1, y1, x2, y2;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool ok(int x, int y)
{
  if (x >= 0 && y >= 0 && x < n && y < n && lee[x][y] == -1)
    return true;
  return false;
}
void Lee()
{
  memset(lee, -1, sizeof lee);
  lee[x1][y1] = 0;
  q.push(make_pair(x1, y1));
  while (!q.empty())
  {
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    if (cx == x2 && cy == y2)
    {
      while (!q.empty())
        q.pop();
      cout << lee[x2][y2] << "\n";
    }
    else
      for (int i = 0; i < 4; ++i)
      {
        if (a[cx][cy][i] == '1')
        {
          int hx = cx + dx[i], hy = cy + dy[i];
          if (ok(hx, hy))
          {
            lee[hx][hy] = lee[cx][cy] + 1;
            q.push(make_pair(hx, hy));
          }
        }
      }
  }
  if (lee[x2][y2] == -1)
    cout << "Impossible\n";
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  while (cin >> n)
  {
    if (n == 0)
      return 0;
    for (int y = n - 1; y >= 0; --y)
      for (int x = 0; x < n; ++x)
      {
        a[y][x] = "";
        for (int i = 1; i <= 4; ++i)
        {
          cin >> v;
          a[y][x] += v;
        }
      }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
      cin >> y1 >> x1 >> y2 >> x2;
      Lee();
    }
    cout << "\n";
  }
  return 0;
}
