#include <fstream>
using namespace std;
ifstream fin("partnr.in");
ofstream fout("partnr.out");
int st[101], n;
void afisare(int p)
{
  for (int i = 1; i <= p; ++i)
    fout << st[i] << " ";
  fout << "\n";
}
void back(int p, int s)
{
  for (int i = st[p - 1]; i <= n; ++i)
  {
    st[p] = i;
    if (s - i >= 0)
    {
      if (s == i)
        afisare(p);
      else if (p < n)
        back(p + 1, s - i);
    }
    else
      return;
  }
}
int main()
{
  st[0] = 1;
  fin >> n;
  back(1, n);
  return 0;
}