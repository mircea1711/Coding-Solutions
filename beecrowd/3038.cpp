#include <iostream>

using namespace std;

int main()
{
  string a;
  while (getline(cin, a))
  {
    for (int i = 0; a[i]; ++i)
      if (a[i] == '@')
        a[i] = 'a';
      else if (a[i] == '&')
        a[i] = 'e';
      else if (a[i] == '!')
        a[i] = 'i';
      else if (a[i] == '*')
        a[i] = 'o';
      else if (a[i] == '#')
        a[i] = 'u';
    cout << a << "\n";
  }
  return 0;
}
