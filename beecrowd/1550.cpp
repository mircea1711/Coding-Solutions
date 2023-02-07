#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define NMAX 10005
using namespace std;
int d[NMAX];
vector<int> v[NMAX];
int pal(int n)
{
  int a = n, nr = 0;
  while (a)
  {
    nr *= 10;
    nr += a % 10;
    a /= 10;
  }
  return nr;
}
void rez()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int a, b, t;
  cin >> t;
  while (t--)
  {
    memset(d, 0, sizeof(d));
    cin >> a >> b;
    if (a == b)
      cout << "0\n";
    else
    {
      queue<int> q;
      q.push(a);
      while (d[b] == 0)
      {
        int n = q.front();
        q.pop();
        if (n < 10000 && d[n + 1] == 0)
          v[n].push_back(n + 1);
        if (pal(n) < 10000 && d[pal(n)] == 0 && pal(n) != n)
          v[n].push_back(pal(n));
        for (int i = 0; i < v[n].size(); ++i)
        {
          if (d[v[n][i]] == 0)
          {
            d[v[n][i]] = d[n] + 1;
            q.push(v[n][i]);
          }
        }
      }
      cout << d[b] << "\n";
    }
  }
}
int main()
{
  rez();
  return 0;
}
