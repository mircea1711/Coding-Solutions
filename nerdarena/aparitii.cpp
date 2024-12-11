#include <fstream>
using namespace std;
ifstream cin("aparitii.in");
ofstream cout("aparitii.out");

int main()
{
  int n, a, rez;
  cin >> n;
  cin >> a;
  rez = a;
  for (int i = 2; i <= 2 * n - 1; ++i)
  {
    cin >> a;
    rez = rez ^ a;
  }
  cout << rez;
  return 0;
}