#include <fstream>
#include <vector>

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

InParser fin("triunghiuri2.in");
std::ofstream fout("triunghiuri2.out");

const int NMAX = 1002;
const int MOD = 1000003;

int x, y, n, p, tx[NMAX], ty[NMAX];

std::vector<int> v[NMAX];

int main()
{
  int max = 0;

  fin >> p >> n;

  for (int i = 1; i <= n; ++i)
  {
    fin >> x >> y;
    ++tx[x];
    ++ty[y];
    if (tx[x] > max)
      max = tx[x];
    v[y].push_back(x);
  }

  if (p == 1)
    fout << max << "\n";

  else
  {
    unsigned long long countTriangles = 0;
    for (int i = 0; i < 1000; ++i)
      if (ty[i] > 1)
      {
        unsigned long long lineSum = 0, pointsNumber = ((1LL * ty[i] * (1LL * ty[i] - 1)) >> 1LL), remainingPoints = (n - ty[i]);
        for (auto j : v[i])
          lineSum += 1LL * (tx[j] - 1) * 1LL * (ty[i] - 1);
        countTriangles += pointsNumber * remainingPoints - lineSum;
        countTriangles %= MOD;
      }
    fout << countTriangles << '\n';
  }

  fout.close();
  return 0;
}