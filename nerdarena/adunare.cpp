
#include <fstream>

using namespace std;

int main()
{
  ifstream cin("adunare.in");
  ofstream cout("adunare.out");
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
  return 0;
}