#include <iostream>
#include <vector>
#include <bitset>

const int NMAX = 1001;

std::vector<int> g[NMAX];
std::vector<int> daddies;

std::bitset<NMAX> used;

int n, m, p, f, r[NMAX], l[NMAX];

bool pair_up(int node)
{
  if (used[node])
    return 0;

  used[node] = 1;

  for (auto i : g[node])
  {
    if (!l[i] || pair_up(l[i]))
    {
      l[i] = node;
      r[node] = i;
      return 1;
    }
  }
  return 0;
}

int main()
{
  while (std::cin >> n >> m)
  {
    daddies.clear();

    for (int i = 1; i <= n; ++i)
    {
      l[i] = 0;
      r[i] = 0;
      g[i].clear();
    }
    used.reset();

    for (int i = 1; i <= m; ++i)
    {
      std::cin >> p >> f;
      g[f].push_back(p);
    }

    int ans = n;

    for (bool ok = true; ok;)
    {
      ok = 0;
      used.reset();
      for (int i = 1; i <= n; ++i)
        if (!r[i] && pair_up(i))
        {
          --ans;
          ok = 1;
        }
    }

    std::cout << ans << '\n';
  }

  return 0;
}