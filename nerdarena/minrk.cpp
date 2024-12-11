#include <fstream>
using namespace std;
int fr[10];
int main()
{
  int k, min = 10, i, j;
  string n;
  ifstream cin("minnrk.in");
  ofstream cout("minnrk.out");
  cin >> n >> k;
  for (int i = 0; i < n.size(); ++i)
  {
    fr[n[i] - '0']++;
    if (n[i] - '0' < min && n[i] - '0')
      min = n[i] - '0';
  }
  cout << min;
  fr[min]--;
  k--;
  for (int i = 0; i <= 9; ++i)
    for (int j = 1; j <= fr[i]; ++j)
    {
      cout << i;
      k--;
      if (k == 0)
        return 0;
    }
  return 0;
}