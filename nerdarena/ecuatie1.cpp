#include <fstream>

using namespace std;

int main()
{
  ifstream fin("ecuatie1.in");
  ofstream fout("ecuatie1.out");
  int a, b;
  fin >> a >> b;
  if (a != 0 && b % a == 0)
    fout << -b / a;
  else if (a == 0 && b == 0)
    fout << "multimea Z";
  else
    fout << "multimea vida";

  return 0;
}