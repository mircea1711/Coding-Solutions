#include <iostream>

using namespace std;

int main()
{
  int n, i = 1, c;
  while (cin >> n && n >= 0)
  {
    c = n / 2;
    cout << "Experiment " << i << ": " << c << " full cycle(s)" << endl;
    i++;
  }

  return 0;
}