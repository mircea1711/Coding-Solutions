
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("submultimi.in");
ofstream fout("submultimi.out");
int a[10], n, k, val, cnt;
int st[30];
void afisare(int p)
{
  for (int i = 1; i <= p; ++i)
    fout << st[i] << " ";
  fout << "\n";
}
bool valid(int p)
{
  int suma = 0;
  for (int i = 1; i <= p; ++i)
    suma += st[i];
  if (suma & 1)
    return false;
  return true;
}
void back(int p)
{
  for (int i = st[p - 1] + 1; i <= n; ++i)
  {
    st[p] = i;
    if (valid(p))
    {
      cnt++;
      if (a[val] == cnt)
      {
        afisare(p);
        val++;
      }
    }
    if (p < n)
      back(p + 1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  fin.tie(NULL);
  fin >> n >> k;
  for (int i = 1; i <= k; ++i)
    fin >> a[i];
  val = 1;
  back(1);
  return 0;
}