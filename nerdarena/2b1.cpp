#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream cin("2b1.in");
ofstream cout("2b1.out");

int main()
{
  ull n, i = 1, j;
  cin >> n;
  while ((1ULL << i) < n)
  {
    for (j = 0; j < i; ++j)
      if ((1ULL << i) + (1ULL << j) <= n)
        cout << (1ULL << i) + (1ULL << j) << " ";
    i++;
  }
  return 0;
}