
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
  ifstream cin("numchar.in");
  ofstream cout("numchar.out");
  int cntd = 0, cntl = 0, n, i;
  char a;
  cin >> n;
  for (i = 0; i <= n; ++i)
  {
    cin.get(a);
    if (isdigit(a))
      cntd++;
    else if (isalpha(a))
      cntl++;
  }
  cout << cntl << " " << cntd;
  return 0;
}