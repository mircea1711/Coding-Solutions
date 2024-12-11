#include <fstream>

using namespace std;

int main()
{
  ifstream fin("triunghiuri.in");
  ofstream fout("triunghiuri.out");
  long long int n, sum = 0, i;
  fin >> n;
  sum = n;
  for (i = 1; i <= n; i++)
    sum += (i * (i + 1)) / 2;
  long long int p = sum / 20;
  fout << p << " " << (sum - p * 20) * 5;
  return 0;
}