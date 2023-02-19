#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("parola.in");
ofstream cout("parola.out");
char a[15], b[15];
int main()
{
  int k;
  cin >> k;
  cin >> a >> b;
  for (int i = 0; i < strlen(b) / 2; ++i)
    swap(b[i], b[strlen(b) - i - 1]);
  for (int i = 0; i < k; ++i)
    cout << a[i];
  cout << b[0];
  int h = max(strlen(b), strlen(a)) + k;
  for (int i = k; i < h; ++i)
  {
    if (a[i])
      cout << a[i];
    if (b[i - k + 1] != 0)
      cout << b[i - k + 1];
  }
  return 0;
}