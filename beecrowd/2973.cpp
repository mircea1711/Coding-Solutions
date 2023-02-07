#include <bits/stdc++.h>

#define NMAX 100005
using namespace std;
bool check(int mid, int array[], int n, int K)
{
  int count = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (array[i] > mid)
      return false;
    sum += array[i];
    if (sum > mid)
    {
      count++;
      sum = array[i];
    }
  }
  count++;
  if (count <= K)
    return true;
  return false;
}
int solve(int array[], int n, int K)
{
  int start = 1;
  int end = 0;
  for (int i = 0; i < n; ++i)
    end += array[i];
  int answer = 0;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (check(mid, array, n, K))
    {
      answer = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return answer;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, t, a[NMAX];
  cin >> n >> k >> t;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int x = solve(a, n, k);
  int y = x / t;
  if (y * t != x)
    y++;
  cout << y << "\n";
  return 0;
}
