#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("ecuatie4.in");
ofstream cout("ecuatie4.out");
long long T, nr, a[61][11];
int N;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  for (int i = 1; i <= 10; ++i)
    a[0][i] = 1;
  for (int i = 1; i <= 60; ++i)
    for (int j = 1; j <= 10; ++j)
      a[i][j] = a[i - 1][j] + a[i][j - 1];
  cin >> N >> T;
  int i = 0;
  while (T % 2 == 0)
  {
    T /= 2;
    i++;
  }
  nr = a[i][N];
  long long d = 3;
  while (d * d <= T)
  {
    i = 0;
    while (T % d == 0)
    {
      T /= d;
      i++;
    }
    nr *= a[i][N];
    d += 2;
  }
  if (T > 1)
    nr *= a[1][N];
  cout << nr << "\n";
  return 0;
}
