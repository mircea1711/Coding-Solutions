#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, j, m;
  cin >> n;
  while (n--)
  {
    int a, b;
    j = m = 0;
    for (int i = 1; i <= 3; ++i)
    {
      cin >> a >> b;
      j += a * b;
    }
    for (int i = 1; i <= 3; ++i)
    {
      cin >> a >> b;
      m += a * b;
    }
    if (j > m)
      cout << "JOAO\n";
    else
      cout << "MARIA\n";
  }
  return 0;
}
