#include <iostream>
#include <cstdlib>

using namespace std;

struct t_node
{
  int val;
  t_node *l, *r;
  t_node(int k) : l(NULL), r(NULL), val(k) {}
};

typedef t_node *pnode;

int find_max(pnode node)
{
  if (node->r)
    return find_max(node->r);
  return node->val;
}

pnode erase(pnode node, int val)
{
  if (node == NULL)
    return NULL;
  if (node->val > val)
  {
    node->l = erase(node->l, val);
  }
  else if (node->val < val)
  {
    node->r = erase(node->r, val);
  }
  else
  {
    if (node->l == NULL && node->r == NULL)
    {
      delete node;
      return NULL;
    }
    if (node->l != NULL && node->r != NULL)
    {
      int tar = find_max(node->l);
      node->val = tar;
      node->l = erase(node->l, tar);
    }
    else if (node->l)
    {
      pnode c = node->l;
      delete node;
      return c;
    }
    else if (node->r)
    {
      pnode c = node->r;
      delete node;
      return c;
    }
  }
  return node;
}

pnode insert(pnode node, int val)
{
  if (node == NULL)
  {
    return new t_node(val);
  }

  if (node->val >= val)
  {
    node->l = insert(node->l, val);
    return node;
  }
  else if (node->val < val)
  {
    node->r = insert(node->r, val);
    return node;
  }
}

pnode search(pnode node, int val)
{
  if (node == NULL)
    return NULL;
  if (node->val == val)
    return node;
  else if (node->val > val)
    return search(node->l, val);
  else
    return search(node->r, val);
}

int first;
void pref(pnode node)
{
  if (node == NULL)
    return;
  if (!first)
    cout << ' ';
  first = false;
  cout << (node->val);
  pref(node->l);
  pref(node->r);
}

void inf(pnode node)
{
  if (node == NULL)
    return;
  inf(node->l);
  if (!first)
    cout << ' ';
  first = false;
  cout << (node->val);
  inf(node->r);
}

void posf(pnode node)
{
  if (node == NULL)
    return;
  posf(node->l);
  posf(node->r);
  if (!first)
    cout << ' ';
  first = false;
  cout << (node->val);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string op;
  pnode root = NULL;
  while (cin >> op)
  {
    if (op == "I")
    {
      int val;
      cin >> val;
      root = insert(root, val);
    }
    if (op == "P")
    {
      int val;
      cin >> val;
      pnode cur = search(root, val);
      if (cur == NULL)
        cout << val << " nao existe\n";
      else
        cout << val << " existe\n";
    }

    if (op == "R")
    {
      int val;
      cin >> val;
      root = erase(root, val);
    }

    if (op == "INFIXA")
    {
      first = true;
      inf(root);
      cout << endl;
    }

    if (op == "PREFIXA")
    {
      first = true;
      pref(root);
      cout << "\n";
    }

    if (op == "POSFIXA")
    {
      first = true;
      posf(root);
      cout << "\n";
    }
  }
  return 0;
}
