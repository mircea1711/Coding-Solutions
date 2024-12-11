#include <iostream>
#include <vector>
#include <bitset>

class Read
{
public:
  template <class T>
  Read &operator>>(T &number)
  {
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
      negative = true;
      c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
      number = number * 10 + c - 48;

    if (negative)
      number *= -1;

    return *this;
  }
};

Read cin;

std::vector<int> g[101];
std::bitset<101> used;

void DFS(int node)
{
  used[node] = 1;
  for (auto i : g[node])
    if (!used[i])
      DFS(i);
}

int main()
{
  int c, n, m, x, y;
  cin >> c;

  for (int e = 1; e <= c; ++e)
  {
    std::cout << "Caso #" << e << ": ";

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
      g[i].clear();
    used.reset();

    for (int i = 1; i <= m; ++i)
    {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    int ans = -1;

    for (int i = 1; i <= n; ++i)
      if (used[i] == 0)
      {
        ++ans;
        DFS(i);
      }

    if (ans == 0)
      std::cout << "a promessa foi cumprida\n";
    else
      std::cout << "ainda falta(m) " << ans << " estrada(s)\n";
  }

  return 0;
}