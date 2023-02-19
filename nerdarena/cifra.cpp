#include <iostream>
#include <cstdio>
using namespace std;

FILE *f = fopen("cifra.in", "r");
FILE *g = fopen("cifra.out", "w");

int main()
{
  int n, c;
  fscanf(f, "%d %d", &n, &c);
  while (c <= n)
  {
    fprintf(g, "%d ", c);
    c += 9;
  }
  return 0;
}