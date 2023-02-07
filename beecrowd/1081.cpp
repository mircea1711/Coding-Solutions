#include <iostream>
#include <string.h>
using namespace std;
int a[30][30];
bool viz[30], ok;
int n, m;
void DFS(int x, int cnt)
{
  cnt += 2;
  viz[x] = 1;
  for (int i = 0; i < n; ++i)
    if (a[x][i])
    {
      ok = 1;
      for (int j = 0; j < cnt; ++j)
        cout << " ";
      cout << x << "-" << i;
      if (!viz[i])
      {
        cout << " pathR(G," << i << ")\n";
        DFS(i, cnt);
      }
      else
        cout << "\n";
    }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int k = 1; k <= t; ++k)
  {
    cout << "Caso " << k << ":\n";
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(viz, 0, sizeof(viz));
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
      cin >> x >> y;
      a[x][y] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
      if (!viz[i])
        DFS(i, 0);
      if (ok)
      {
        cout << "\n";
        ok = 0;
      }
    }
  }
  return 0;
}
