#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#define NMAX 10005
using namespace std;
vector<int> G[NMAX];
int viz[NMAX], tt[NMAX];
int n, m;
bool ciclu;
bool are_ciclu(int x)
{
  stack<int> s;
  s.push(x);
  while (!s.empty())
  {
    int t = s.top();
    s.pop();
    if (viz[t])
      continue;
    viz[t] = true;
    for (size_t i = 0; i < G[t].size(); ++i)
    {
      int x = G[t][i];
      if (tt[t] == x)
        continue;
      if (viz[x])
        return true;
      if (tt[x] == t)
        return true;
      tt[x] = t;
      s.push(x);
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  while (cin >> n >> m)
  {
    for (int i = 1; i <= n; ++i)
      G[i].clear();
    ciclu = 0;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
      cin >> a >> b;
      if (a == b)
        ciclu = true;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
      tt[i] = i;
    memset(viz, 0, sizeof viz);
    for (int i = 1; i <= n; ++i)
    {
      if (!viz[i])
        ciclu |= are_ciclu(i);
      if (ciclu)
        break;
    }
    if (ciclu)
      cout << "Inseguro\n";
    else
      cout << "Seguro\n";
  }
  return 0;
}
