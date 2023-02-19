
#include <fstream>
#define NMAX 1000000
using namespace std;
ifstream cin("kdiv.in");
ofstream cout("kdiv.out");
char nrdiv[NMAX + 5];
int main()
{
  for (int j = 2; j <= NMAX + 5; j += 2)
    nrdiv[j] = 1;
  for (int i = 3; i <= NMAX + 5; i += 2)
    if (nrdiv[i] == 0)
    {
      for (int j = i; j <= NMAX + 5; j += i)
        ++nrdiv[j];
    }
  int n, k, cnt = 0, a;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a;
    if (nrdiv[a] == k)
      ++cnt;
  }
  cout << cnt;
  return 0;
}