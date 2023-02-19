#include <fstream>
#include <list>
using namespace std;
ifstream cin("greieri.in");
ofstream cout("greieri.out");
int main()
{
  unsigned long long n, m;
  list<int> v;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    v.push_back(i);
  cout << n * (n - 1) << "\n";
  unsigned long long c = m % (n * (n - 1));
  for (int i = 1; i <= c / (n - 1); ++i)
  {
    v.push_front(v.back());
    v.pop_back();
  }
  c %= (n - 1);
  list<int>::iterator it = v.begin();
  advance(it, n - c - 1);
  v.insert(it, v.back());
  v.pop_back();
  for (it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  return 0;
}