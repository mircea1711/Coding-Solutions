
#include <fstream>
#include <bitset>
#include <vector>
#include <algorithm>
#define NMAX 100000
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bitset<NMAX + 5> ciur;
vector<int> v;

int n, cnt;

int main()
{
  fin >> n;
  v.push_back(2);

  ciur[0] = ciur[1] = 1;

  for (int i = 4; i <= n; i += 2)
    ciur[i] = 1;
  for (long long i = 3; i <= n / 2; i += 2)
    if (ciur[i] == 0)
    {
      v.push_back(i);
      for (long long j = i * i; j <= n; j += i)
        ciur[j] = 1;
    }

  for (size_t i = 0; i < v.size(); ++i)
    for (size_t j = i; j < v.size() && v[i] + v[j] < n; ++j)
      if (ciur[n - v[i] - v[j]] == 0 && n - v[i] - v[j] >= v[j])
        cnt++;

  fout << cnt << "\n";
  return 0;
}