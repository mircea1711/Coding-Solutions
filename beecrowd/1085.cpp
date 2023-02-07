#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef std::pair<std::string, int> si;
typedef std::pair<si, std::string> sis;
typedef std::pair<std::string, std::string> ss;

std::map<std::string, std::vector<ss>> m;

struct cmp
{
  const inline bool operator()(const sis &a, const sis &b)
  {
    return a.first.second > b.first.second;
  }
};

int n;
std::string start, finish, l1, l2, word;

int solve()
{
  std::priority_queue<sis, std::vector<sis>, cmp> q;

  q.push({{start, 0}, " "});

  std::set<std::string> used;

  while (!q.empty())
  {
    sis p = q.top();
    q.pop();

    if (p.first.first == finish)
      return p.first.second;

    if (used.find(p.second) != used.end())
      continue;

    used.insert(p.second);

    for (auto i : m[p.first.first])
      if (used.find(i.second) == used.end() && p.second[0] != i.second[0])
        q.push({{i.first, p.first.second + i.second.size()}, i.second});
  }
  return -1;
}
int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(NULL);
  std::cin >> n;
  while (n)
  {
    m.clear();
    std::cin >> start >> finish;
    for (int i = 1; i <= n; ++i)
    {
      std::cin >> l1 >> l2 >> word;
      m[l1].push_back({l2, word});
      m[l2].push_back({l1, word});
    }
    int val = solve();
    if (val == -1)
      std::cout << "impossivel\n";
    else
      std::cout << val << '\n';
    std::cin >> n;
  }
  return 0;
}