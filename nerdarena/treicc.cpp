#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("treicc.in");
ofstream fout("treicc.out");
int a[10], n, k, val, cnt;
char st[10];
bool valid(int p)
{
  if (p == 0 && st[0] == '0')
    return false;
  if (p > 1 && (st[p - 2] & 1) == (st[p - 1] & 1) && (st[p - 2] & 1) == (st[p] & 1))
    return false;
  return true;
}
void back(int p)
{
  for (char i = '0'; i <= '9'; ++i)
  {
    st[p] = i;
    if (valid(p))
    {
      if (p == n - 1)
      {
        cnt++;
        if (a[val] == cnt)
        {
          fout << st << "\n";
          val++;
        }
      }
      else
        back(p + 1);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  fin.tie(NULL);
  fin >> n >> k;
  val = 1;
  for (int i = 1; i <= k; ++i)
    fin >> a[i];
  back(0);
  return 0;
}