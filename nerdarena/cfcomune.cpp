#include <fstream>

using namespace std;
ifstream cin("cfcomune.in");
ofstream cout("cfcomune.out");
int fra[10], fr[10], cnt;
int main()
{
  int a, b;
  cin >> a >> b;
  while (a)
  {
    ++fra[a % 10];
    a /= 10;
  }
  while (b)
  {
    ++fr[b % 10];
    b /= 10;
  }
  for (int i = 0; i <= 9; ++i)
  {
    if (fr[i] && fra[i])
      ++cnt;
  }
  cout << cnt;
  return 0;
}