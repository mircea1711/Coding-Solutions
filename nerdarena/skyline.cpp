
#include <fstream>
#include <stack>

using namespace std;

const int NMAX = 40005;

struct skyline
{
  int val, s, d, suma;
};

skyline a[NMAX];

ifstream fin("skyline.in");
ofstream fout("skyline.out");

int n;

stack<int> st;

int main()
{
  fin >> n;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i].val >> a[i].suma;
    a[i].suma += a[i - 1].suma;

    a[i].s = 0;
    a[i].d = n;
    while (!st.empty() && a[st.top()].val >= a[i].val)
    {
      a[st.top()].d = i - 1;
      st.pop();
    }

    if (!st.empty())
      a[i].s = st.top();

    st.push(i);
  }

  int64_t maxi = 0;

  for (int i = 1; i <= n; ++i)
  {
    int64_t val = 1LL * (a[a[i].d].suma - a[a[i].s].suma) * a[i].val;
    maxi = (val > maxi) ? val : maxi;
  }
  fout << maxi << "\n";

  return 0;
}