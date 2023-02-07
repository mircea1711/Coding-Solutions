#include <iostream>

using namespace std;

int main()
{
  int a, cnt = 225;
  cin >> a;
  cnt += 300 * a;
  cin >> a;
  cnt += 1500 * a;
  cin >> a;
  cnt += 600 * a;
  cin >> a;
  cnt += 1000 * a;
  cin >> a;
  cnt += 150 * a;
  cout << cnt << "\n";
  return 0;
}
