#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define NMAX 1005
#define oo (1 << 30)
using namespace std;
int n, m, d[NMAX];
bool InCoada[NMAX];
vector<pair<int, int>> G[NMAX];
struct compara
{
  bool operator()(int x, int y)
  {
    return d[x] > d[y];
  }
};
priority_queue<int, vector<int>, compara> coada;
void Dijkstra(int start)
{
  for (int i = 1; i <= n; ++i)
    d[i] = oo;
  d[start] = 0;
  coada.push(start);
  InCoada[start] = true;
  while (!coada.empty())
  {
    int curent = coada.top();
    coada.pop();
    InCoada[curent] = false;
    for (size_t i = 0; i < G[curent].size(); ++i)
    {
      int vecin = G[curent][i].first, cost = G[curent][i].second;
      if (d[curent] + cost < d[vecin])
      {
        d[vecin] = d[curent] + cost;
        if (InCoada[vecin] == false)
        {
          coada.push(vecin);
          InCoada[vecin] = true;
        }
      }
    }
  }
}
void Solve()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int max = 0, min = oo;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
    G[y].push_back(make_pair(x, c));
  }
  int k;
  cin >> k;
  Dijkstra(k);
  for (int i = 1; i <= n; ++i)
  {
    if (d[i] > max && i != k)
      max = d[i];
    if (d[i] < min && i != k)
      min = d[i];
  }
  cout << max - min << "\n";
}
int main()
{
  Solve();
  return 0;
}
