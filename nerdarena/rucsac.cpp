#include <fstream>
using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

const int NMAX = 502;
const int MOD = 999979;

int dp[NMAX * NMAX], n, k, a;

int main()
{
  dp[0] = 1;
  fin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    for (int j = k; j >= a; --j)
    {
      dp[j] += dp[j - a];
      if (dp[j] >= MOD)
        dp[j] -= MOD;
    }
  }
  fout << dp[k] << "\n";
  return 0;
}