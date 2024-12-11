#include <iostream>
#include <bitset>
using namespace std;

bitset<10001> ciur;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  for (int i = 4; i <= 10001; i += 2)
    ciur[i] = 1;
  for (int i = 3; i <= 10001; i += 2)
    if (ciur[i] == 0)
      for (int j = i * i; j <= 10001; j += i)
        ciur[j] = 1;
  int n, a;
  cin >> n;
  while (n--)
  {
    cin >> a;
    a++;
    if (ciur[a + 2] == 0 && (a & 1) && a % 7 == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
