#include <fstream>
using namespace std;
int n;
ifstream fin("paranteze.in");
ofstream fout("paranteze.out");
char a[] = "()", st[101];
bool valid(int cntp, int cntn)
{
  if (cntp > n || cntn > cntp)
    return false;
  return true;
}
void back(int p, int cntp, int cntn)
{
  for (int i = 0; i < 2; ++i)
  {
    st[p] = a[i];
    if (i == 0)
    {
      if (valid(cntp + 1, cntn))
      {
        if (p == 2 * n - 1)
          fout << st << "\n";
        else
          back(p + 1, cntp + 1, cntn);
      }
    }
    else
    {
      if (valid(cntp, cntn + 1))
      {
        if (p == 2 * n - 1)
          fout << st << "\n";
        else
          back(p + 1, cntp, cntn + 1);
      }
    }
  }
}
int main()
{
  fin >> n;
  back(0, 0, 0);
  return 0;
}