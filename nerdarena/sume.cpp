#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("sume.in");
ofstream fout("sume.out");

vector<int> v;

int n, k, a, fr[2001];

int main()
{
  fin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    ++fr[a + 1000];
  }
  for (int i = 2000; i >= 0; --i)
    while (fr[i])
    {
      v.push_back(i - 1000);
      --fr[i];
    }
  int s1 = v[0], s2 = v[0];
  for (int i = 1; i < k; ++i)
  {
    s1 += v[i];
    if (v[i] >= 0)
      s2 += v[i];
  }
  for (int i = k; i < n; ++i)
    if (v[i] > 0)
      s1 += v[i];
    else
      break;
  fout << s1 << "\n"
       << s2;
  return 0;
}
