#include <fstream>
#include <vector>
#include <algorithm>

class InParser
{
#pragma warning(disable : 4996)
private:
  FILE *fin;
  char *buff;
  int sp;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  InParser(const char *nume)
  {
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
  }
  InParser &operator>>(int &n)
  {
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("antitir.in");
std::ofstream fout("antitir.out");

typedef std::vector<int> VI;

const unsigned long long MAX = 1e19;

VI cx, cy;
int x, y, n;

unsigned long long solve(VI &v)
{
  unsigned long long sum = (0);
  sort(v.begin(), v.end());

  for (int i = 1; i < n; ++i)
  {
    v[i] += -v[0];
    sum += abs(v[i]);
  }

  v[0] = 0;

  int l = 0, r = n, i = 0;

  while (i < n - 1 && v[i] == v[i + 1])
  {
    ++l;
    --r;
    ++i;
  }

  ++i;
  --r;
  ++l;

  unsigned long long min = sum;

  for (; i < n - 1; ++i)
  {
    sum = sum + 1LL * (l - r) * abs(v[i] - v[i - 1]);

    if (sum < min)
      min = sum;

    while (i < n - 1 && v[i] == v[i + 1])
    {
      ++i;
      ++l;
      --r;
    }
    ++l;
    --r;
  }
  return min;
}

int main()
{
  fin >> n;

  cx.resize(n);
  cy.resize(n);

  for (int i = 0; i < n; ++i)
    fin >> cx[i] >> cy[i];

  fout << solve(cx) + solve(cy) << '\n';

  fout.close();
  return 0;
}