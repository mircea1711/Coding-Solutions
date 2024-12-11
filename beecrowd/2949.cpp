#include <iostream>
using namespace std;
int cnt1, cnt2, cnt3, cnt4, cnt5;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string a;
  char b;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a >> b;
    if (b == 'X')
      cnt1++;
    else if (b == 'H')
      cnt2++;
    else if (b == 'E')
      cnt3++;
    else if (b == 'A')
      cnt4++;
    else
      cnt5++;
  }
  cout << cnt1 << " Hobbit(s)\n"
       << cnt2 << " Humano(s)\n"
       << cnt3 << " Elfo(s)\n"
       << cnt4 << " Anao(s)\n"
       << cnt5 << " Mago(s)\n";
  return 0;
}
