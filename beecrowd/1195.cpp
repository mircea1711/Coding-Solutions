#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct nod
{
  int val;
  struct nod *left;
  struct nod *right;
} Nod;
Nod *insert(Nod *ST, int val)
{
  if (!ST)
  {
    ST = (Nod *)malloc(sizeof(Nod));
    ST->val = val;
    ST->left = NULL;
    ST->right = NULL;
  }
  else if (ST->val > val)
    ST->left = insert(ST->left, val);
  else
    ST->right = insert(ST->right, val);
  return ST;
}
void Post(Nod *ST)
{
  if (ST == NULL)
    return;
  Post(ST->left);
  Post(ST->right);
  cout << " " << ST->val;
}
void In(Nod *ST)
{
  if (ST == NULL)
    return;
  In(ST->left);
  cout << " " << ST->val;
  In(ST->right);
}
void Pre(Nod *ST)
{
  if (ST == NULL)
    return;
  cout << " " << ST->val;
  Pre(ST->left);
  Pre(ST->right);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int j = 1; j <= t; ++j)
  {
    Nod *BST = NULL;
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
      cin >> a;
      BST = insert(BST, a);
    }
    cout << "Case " << j << ":\n";
    cout << "Pre.:";
    Pre(BST);
    cout << "\n";
    cout << "In..:";
    In(BST);
    cout << "\n";
    cout << "Post:";
    Post(BST);
    cout << "\n\n";
  }
  return 0;
}
