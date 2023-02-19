
#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;
ifstream cin("apropiate.in");
ofstream cout("apropiate.out");
bitset<400001> ciur;
int main()
{
  ciur[1] = 1;
  for (int i = 4; i <= 40000; i += 2)
    ciur[i] = 1;
  for (int i = 3; i <= 40000; i += 2)
    if (ciur[i] == 0)
    {
      for (int j = i + i; j <= 40000; j += i)
        ciur[j] = 1;
    }
  int n, x;
  char c;
  cin >> n >> c;
  for (int i = 1; i <= n; ++i)
  {
    cin >> x;
    if (ciur[x] == 0)
      cout << x << " ";
    else
    {
      int st = x - 1, dr = x + 1;
      while (ciur[st] == 1 && ciur[dr] == 1)
      {
        st = st - 1;
        dr = dr + 1;
      }
      if (ciur[st] == 0)
      {
        if (ciur[dr] == 1)
          cout << st << " ";
        else
        {
          if (c == '1')
            cout << st << " ";
          else
            cout << dr << " ";
        }
      }
      else
        cout << dr << " ";
    }
  }
  return 0;
}