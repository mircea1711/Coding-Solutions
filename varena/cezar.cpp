#include <fstream>

using namespace std;

ifstream fin("cezar.in");
ofstream fout("cezar.out");

const int NMAX = 1e5 + 1;

char s[NMAX];

int main()
{
  ios_base::sync_with_stdio(0);
  fin.tie(NULL);
  fin.get(s, NMAX);
  while (s[0])
  {
    for (int i = 0; s[i]; ++i)
      if (s[i] == 'z')
        s[i] = 'a';
      else
        ++s[i];
    fout << s;
    fin.get(s, NMAX);
  }
  return 0;
}