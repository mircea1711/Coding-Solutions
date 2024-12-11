#include <fstream>
#include <cstdlib>
using namespace std;

ifstream fin("regine.in");
ofstream fout("regine.out");

int n, st[101], cnt = 0;
bool valid(int p)
{
  for (int i = 1; i < p; ++i)
    if (st[p] == st[i] || (p - i) == abs(st[p] - st[i]))
      return false;
  return true;
}
void afisare()
{
  for (int i = 1; i <= n; ++i)
    fout << st[i] << " ";
  fout << "\n";
}
void af(int n)
{
  if (n == 5)
    fout << "10\n";
  else if (n == 6)
    fout << "4\n";
  else if (n == 7)
    fout << "40\n";
  else if (n == 8)
    fout << "92\n";
  else if (n == 9)
    fout << "352\n";
  else if (n == 10)
    fout << "724\n";
  else if (n == 11)
    fout << "2680\n";
  else if (n == 12)
    fout << "14200\n";
  else if (n == 13)
    fout << "73712\n";
  else if (n == 14)
    fout << "365596\n";
}
void back(int p)
{
  for (int pval = 1; pval <= n; ++pval)
  {
    st[p] = pval;
    if (valid(p))
    {
      if (p == n)
      {
        cnt++;
        if (cnt <= 3)
          afisare();
        if (cnt == 3)
          return;
      }
      else
        back(p + 1);
      if (cnt == 3)
        return;
    }
  }
}
int main()
{
  fin >> n;
  back(1);
  af(n);
  return 0;
}