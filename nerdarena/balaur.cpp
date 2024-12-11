
#include <fstream>

using namespace std;

int main()
{
  ifstream fin("balaur.in");
  ofstream fout("balaur.out");
  int n;
  fin >> n;
  fout << 5 * n;
  return 0;
}