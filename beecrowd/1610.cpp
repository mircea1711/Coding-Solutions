#include <iostream>
#include <set>
#include <string.h>
#define maxim 10001
using namespace std;
set<int> g[maxim];
int vizitat[maxim];
bool ciclu;
void DFS(int x)
{
  vizitat[x] = 1;
  if (ciclu)
    return;
  set<int>::iterator it;
  for (it = g[x].begin(); it != g[x].end(); ++it)
    if (vizitat[*it] == 1)
    {
      ciclu = 1;
      return;
    }
    else if (vizitat[*it] == 0)
      DFS(*it);
  vizitat[x] = 2;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, t, m, a, b;
  cin >> t;
  for (int k = 1; k <= t; ++k)
  {
    cin >> n >> m;
    memset(vizitat, 0, sizeof(vizitat));
    for (int i = 0; i <= n; ++i)
      g[i].clear();
    ciclu = 0;
    for (int i = 1; i <= m; ++i)
    {
      cin >> a >> b;
      g[a].insert(b);
    }
    for (int i = 1; i <= n; ++i)
    {
      if (!vizitat[i])
        DFS(i);
      if (ciclu)
        break;
    }
    if (ciclu)
      cout << "SIM\n";
    if (!ciclu)
      cout << "NAO\n";
  }
  return 0;
}
