#include <fstream>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 3e8;

struct s
{
  unsigned long long c, r;
};

struct cmp
{
  inline bool operator()(s a, s b)
  {
    if (a.c == b.c)
      return a.r > b.r;
    return a.c > b.c;
  }
};

priority_queue<s, vector<s>, cmp> q;

ifstream fin("2x3y5z.in");
ofstream fout("2x3y5z.out");

int n;

void afiseaza(s a)
{
  a.c *= 3;
  bool ok = (a.c > 0);
  string b = "", k = "";
  while (a.c)
  {
    char c = a.c % 10 + '0';
    b += c;
    a.c /= 10;
  }
  reverse(b.begin(), b.end());
  while (a.r)
  {
    char c = a.r % 10 + '0';
    k += c;
    a.r /= 10;
  }
  reverse(k.begin(), k.end());
  if (ok)
  {
    if (k.size() < 8)
      while (k.size() < 8)
        k.insert(k.begin(), '0');
    else if (k.size() == 9)
    {
      char c = k.front();
      int ind = b.size() - 1;
      k.erase(k.begin());
      while (ind >= 0 && c != '0')
      {
        int val = c + b[ind] - '0' - '0';
        b[ind] = val % 10 + '0';
        c = val / 10 + '0';
        ind--;
      }
    }
  }
  fout << b << k << "\n";
}

s construieste(s a, int x)
{
  a.r *= x;
  a.c *= x;
  a.c += a.r / MOD;
  a.r %= MOD;
  return a;
}

int main()
{
  fin >> n;
  q.push({0, 1});
  q.push({0, 2});
  q.push({0, 3});
  q.push({0, 5});
  while (!q.empty())
  {
    s x = q.top();
    --n;
    if (n == 0)
    {
      afiseaza(x);
      return 0;
    }
    q.pop();
    if (x.r % 5 == 0)
      q.push(construieste(x, 5));
    else if (x.r % 3 == 0)
    {
      q.push(construieste(x, 3));
      q.push(construieste(x, 5));
    }
    else if (x.r % 2 == 0)
    {
      q.push(construieste(x, 5));
      q.push(construieste(x, 3));
      q.push(construieste(x, 2));
    }
  }
  return 0;
}