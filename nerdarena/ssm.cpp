
#include <fstream>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
  ifstream cin("ssm.in");
  ofstream cout("ssm.out");
  int start = 1, start_i = 1, end = 1, sum = 0, bestsum = INT_MIN, i, n;
  std::vector<int> s(6000001);
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> s[i];
  for (i = 1; i <= n; i++)
  {
    if (sum < 0)
    {
      sum = s[i];
      start_i = i;
    }
    else
      sum = sum + s[i];
    if (sum > bestsum)
    {
      bestsum = sum;
      end = i;
      start = start_i;
    }
  }
  cout << bestsum << " " << start << " " << end;
  return 0;
}
