#include <fstream>

using namespace std;

ifstream cin("pozitii.in");
ofstream cout("pozitii.out");

int main()
{
  int a, n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a;
    if (a == i)
      cnt++;
  }
  cout << cnt;
}