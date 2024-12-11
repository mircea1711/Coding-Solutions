#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("exponent.in");
ofstream cout("exponent.out");

int main()
{
  int cnt = 0, k, n;
  cin >> n >> k;
  for (int i = k; i <= n; i += k)
  {
    int copie = i;
    while (copie % k == 0)
    {
      copie /= k;
      ++cnt;
    }
  }
  cout << cnt;
  return 0;
}