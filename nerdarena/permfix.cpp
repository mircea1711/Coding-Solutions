
#include <fstream>
#include <vector>
using namespace std;
int n, cnt, k, st[15], ind;
vector<int> v;
ifstream fin("permfix.in");
ofstream fout("permfix.out");
void afisare()
{
  for (int i = 1; i <= n; ++i)
    fout << st[i] << " ";
  fout << "\n";
}
void back(int p, bool fr[])
{
  for (int i = 1; i <= n; ++i)
  {
    st[p] = i;
    if (fr[i] == 0 && p != i)
    {
      fr[i] = 1;
      if (p == n)
      {
        cnt++;
        if (v[ind] == cnt)
        {
          ind++;
          afisare();
        }
        if (ind == k)
          return;
      }
      else
        back(p + 1, fr);
      fr[i] = 0;
    }
    if (ind == k)
      return;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  fin.tie(NULL);
  fin >> n >> k;
  v.resize(k);
  for (int i = 0; i < k; ++i)
    fin >> v[i];
  bool fr[15] = {0};
  back(1, fr);
  return 0;
}