#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double c, v, a, n;
  cin >> v;
  c = 300000000;
  a = 700;
  n = a * sqrt((c - v) / (c + v));
  if (n < 400)
    cout << "invisivel\n";
  else if (n < 425)
    cout << "violeta\n";
  else if (n < 445)
    cout << "anil\n";
  else if (n < 500)
    cout << "azul\n";
  else if (n < 575)
    cout << "verde\n";
  else if (n < 585)
    cout << "amarelo\n";
  else if (n < 620)
    cout << "laranja\n";
  else if (n < 750)
    cout << "vermelho\n";
  else
    cout << "invisivel\n";
  return 0;
}
