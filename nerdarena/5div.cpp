#include <fstream>
#include <bitset>
#define NMAX 2000000
using namespace std;
bitset<NMAX + 1> ciur[2];
ifstream cin("5div.in");
ofstream cout("5div.out");
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int cnt = 0, n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i)
  {
    for (int j = i * i; j <= n; j += i)
    {
      int var = 0;
      if (ciur[1][j] == 0)
      {
        while (var < 2 && ciur[var][j] == 1)
          var++;
        if (var == 1 && ciur[1][j] == 0)
          cnt++;
        ciur[var][j] = 1;
      }
    }
  }
  cout << cnt;
  return 0;
}