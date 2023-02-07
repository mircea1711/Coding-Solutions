#include <iostream>

using namespace std;

int main()
{
  string a, b;
  int n, f = 0, m = 0;
  cin >> n;
  while (n--)
  {
    cin >> a >> b;
    if (b == "F")
      f++;
    else
      m++;
  }
  cout << m << " carrinhos\n"
       << f << " bonecas\n";
  return 0;
}
