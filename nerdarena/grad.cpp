
#include <fstream>
#include <sstream>
using namespace std;
ifstream cin("grad.in");
ofstream cout("grad.out");
char f[7000];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, cvt = 0, gr = 0;
  cin >> n;
  cin.get();
  string a, b;
  getline(cin, a);
  stringstream ss(a);
  while (ss >> b)
  {
    cvt++;
    int suma = 0;
    for (int i = 0; i < b.size(); ++i)
      suma += b[i] - 'a' + 1;
    if (f[suma] == 0)
    {
      gr++;
      f[suma] = 1;
    }
  }
  cout << cvt << "\n"
       << gr;
  return 0;
}