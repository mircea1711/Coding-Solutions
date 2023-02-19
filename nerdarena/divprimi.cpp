#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("divprimi.in");
ofstream fout("divprimi.out");

const int NMAX = 1000001;

int n, q, fr[10];
char a[NMAX];
int main()
{
  fin >> n >> q;
  fr[0]++;

  for (int i = 2; i <= n; ++i)
  {
    if (a[i] == 0)
      for (int j = i; j <= n; j += i)
        a[j]++;
    fr[a[i]]++;
  }

  int val = 0;

  for (int i = 0; i < 10; ++i)
  {
    if (q > fr[i])
      q -= fr[i];
    else
    {
      val = i;
      break;
    }
  }

  memset(a, 0, sizeof a);

  for (int i = 2; i <= n; ++i)
  {
    if (a[i] == 0)
      for (int j = i; j <= n; j += i)
        a[j]++;
    if (a[i] == val)
    {
      q--;
      if (q == 0)
      {
        fout << i << "\n";
        return 0;
      }
    };
  }

  return 0;
}