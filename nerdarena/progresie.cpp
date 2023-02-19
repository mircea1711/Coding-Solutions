#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
ifstream cin("progresie.in");
ofstream cout("progresie.out");
int main()
{
  double a, b, c;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a >> b >> c;
    double mij = b - (a + c) / 2.0;
    if (mij < 0)
      mij = -mij;
    cout << fixed << setprecision(1) << mij << "\n";
  }
  return 0;
}