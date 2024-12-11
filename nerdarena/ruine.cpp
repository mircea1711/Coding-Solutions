#include <fstream>
#include <stack>
#include <bitset>

std::ifstream fin("ruine.in");
std::ofstream fout("ruine.out");

const int NMAX = 1e5 + 2;
int t[NMAX], s[NMAX], n, m, a;
char q;

typedef std::pair<char, int> p;
std::stack<p> st1;
std::stack<int> st2;

std::bitset<NMAX> ok;

int find(int x)
{
  if (x == t[x])
    return x;
  return t[x] = find(t[x]);
}

int main()
{
  fin >> n >> m;
  t[1] = 1;

  for (int i = 1; i <= n; ++i)
    fin >> s[i];

  for (int i = 1; i <= m; ++i)
  {
    fin >> q >> a;
    if (q == 'S')
      ok[a] = 1;
    st1.push({q, a});
  }

  for (int i = 1; i < n; ++i)
    if (ok[i] == 0)
    {
      t[i + 1] = t[i];
      s[t[i]] += s[i + 1];
    }
    else
      t[i + 1] = i + 1;

  while (!st1.empty())
  {
    p i = st1.top();
    st1.pop();

    if (i.first == 'T')
      st2.push(s[t[find(i.second)]]);

    else
    {
      s[find(i.second)] += s[t[i.second + 1]];
      t[i.second + 1] = t[i.second];
    }
  }

  while (!st2.empty())
  {
    fout << st2.top() << "\n";
    st2.pop();
  }

  fout.close();
  return 0;
}