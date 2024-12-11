
#include <fstream>
#include <deque>
#define NMAX 100005
using namespace std;

ifstream fin("nrapp.in");
ofstream fout("nrapp.out");

int d[NMAX], s[NMAX], n, q, a;

deque<pair<int, int>> st;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    while (st.size() && st.back().first > a)
    {
      d[st.back().second] = i;
      st.pop_back();
    }
    for (int k = st.size() - 1; k >= 0; --k)
    {
      if (st[k].first != a)
      {
        s[i] = st[k].second;
        break;
      }
    }
    st.push_back(make_pair(a, i));
  }
  fin >> q;
  char x;
  while (q--)
  {
    fin >> x >> a;
    if (x == 'S')
      fout << s[a] << "\n";
    else if (d[a])
      fout << d[a] << "\n";
    else
      fout << n + 1 << "\n";
  }
  return 0;
}