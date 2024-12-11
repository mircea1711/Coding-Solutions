#include <fstream>

using namespace std;

ifstream fin("easy4.in");
ofstream fout("easy4.out");

int cnt, n, k, a;

int main()
{
  fin >> n >> k;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    cnt += ((i & 1) && (a % k == 0));
  }

  fout << cnt << "\n";

  return 0;
}