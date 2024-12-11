#include <fstream>
using namespace std;

int main()
{
  ifstream cin("fgetc.in");
  ofstream cout("fgetc.out");
  int n;
  cin >> n;
  cout << n;
  return 0;
}