#include <iostream>
#include <algorithm>
using namespace std;
const int NMax = 200005;
int N, M, Total, TT[NMax], k, RG[NMax], suma;
struct Edge
{
  int x, y, c;
} V[NMax];
bool Compare(Edge a, Edge b)
{
  return a.c < b.c;
}
void Read()
{
  cin >> N >> M;
  for (int i = 1; i <= M; ++i)
  {
    cin >> V[i].x >> V[i].y >> V[i].c;
    suma += V[i].c;
  }
  sort(V + 1, V + M + 1, Compare);
}
int Find(int nod)
{
  while (TT[nod] != nod)
    nod = TT[nod];
  return nod;
}
void Unite(int x, int y)
{
  if (RG[x] < RG[y])
    TT[x] = y;
  if (RG[y] < RG[x])
    TT[y] = x;
  if (RG[y] == RG[x])
  {
    TT[x] = y;
    RG[y]++;
  }
}
void Solve()
{
  for (int i = 1; i <= M; ++i)
  {
    if (Find(V[i].x) != Find(V[i].y))
    {
      Unite(Find(V[i].x), Find(V[i].y));
      Total += V[i].c;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  Read();
  for (int i = 0; i < N; ++i)
  {
    TT[i] = i;
    RG[i] = 1;
  }
  Solve();
  cout << Total << "\n";
  return 0;
}
