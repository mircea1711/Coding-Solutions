#include <fstream>
using namespace std;
ifstream cin("carte.in");
ofstream cout("carte.out");
int a[10001];
int main()
{
  int max = 0, n, m;
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> m;
    a[m] = i;
  }
  int ac = 1, cnt = 0, ziua = 1;
  for (int i = 1; i < n; ++i)
  {
    if (a[i] < a[i + 1])
      ac++;
    else
    {
      cnt++;
      if (ac > max)
      {
        max = ac;
        ziua = cnt;
      }
      ac = 1;
    }
  }
  cnt++;
  if (ac > max)
  {
    max = ac;
    ziua = cnt;
  }
  cout << cnt << " " << ziua << " " << max;
  return 0;
}
