#include <fstream>
#include <string.h>
using namespace std;
ifstream cin("sumacifre.in");
ofstream cout("sumacifre.out");
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, suma = 0;
  char a;
  cin >> n;
  while (cin >> a)
  {
    if (isdigit(a))
      suma += a - '0';
  }
  cout << suma;
  return 0;
}