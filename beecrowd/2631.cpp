#include <iostream>
#include <vector>
#define NMAX 100001
using namespace std;
vector<int> graf[NMAX];
bool vizita[NMAX];
int lista[NMAX];
int q, n, m, cnt;
void reseteaza()
{
  for (int i = 1; i <= NMAX; ++i)
  {
    graf[i].clear();
    vizita[i] = 0;
    lista[i] = 0;
  }
}
void DFS(int x)
{
  vizita[x] = true;
  for (int i = 0; i < graf[x].size(); ++i)
  {
    if (!vizita[graf[x][i]])
    {
      vizita[graf[x][i]] = true;
      lista[graf[x][i]] = cnt;
      DFS(graf[x][i]);
    }
  }
}
void citeste()
{
  int a, b;
  cin >> n >> m >> q;
  cnt = 1;
  for (int i = 1; i <= m; ++i)
  {
    cin >> a >> b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i)
    if (!vizita[i])
    {
      lista[i] = cnt;
      DFS(i);
      ++cnt;
    }
  for (int i = 0; i < q; ++i)
  {
    cin >> a >> b;
    if (lista[a] == lista[b])
      cout << "S\n";
    else
      cout << "N\n";
  }
  while (cin >> n >> m >> q)
  {
    cout << "\n";
    cnt = 1;
    reseteaza();
    for (int i = 1; i <= m; ++i)
    {
      cin >> a >> b;
      graf[a].push_back(b);
      graf[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
      if (!vizita[i])
      {
        lista[i] = cnt;
        ;
        DFS(i);
        ++cnt;
      }
    for (int i = 0; i < q; ++i)
    {
      cin >> a >> b;
      if (lista[a] == lista[b] && lista[a])
        cout << "S\n";
      else
        cout << "N\n";
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  citeste();
  return 0;
}
