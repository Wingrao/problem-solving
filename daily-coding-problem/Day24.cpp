#include<iostream>

#include<bits/stdc++.h>

using namespace std;
struct node {
  int data;
  node * left;
  node * parent;
  bool lock;
  node * right;
  int decend;
};
node * newNode(int a) {
  node * A = (node * ) malloc(sizeof(node));
  A -> left = NULL;
  A -> right = NULL;
  A -> data = a;
  A -> lock = false;
  A -> parent = NULL;
  A -> decend = 0;
  return A;
}
bool checkParent(node * root) {
  if (root == NULL)
    return false;
  while (root -> parent != NULL) {
    root = root -> parent;
    if (root -> decend > 0 || root -> lock == true)
      return false;
  }
  return true;
}
void propogate(node * root, int data) {
  if (root == NULL)
    return;
  while (root -> parent != NULL) {
    root = root -> parent;
    root -> decend += data;
  }
  return;
}
bool Lock(node * root) {
  if (root == NULL)
    return false;
  if (root -> decend != 0 || checkParent(root) == false)
    return false;
  propogate(root, +1);
  root -> lock = true;
  return true;
}
bool Unlock(node * root) {
  if (root == NULL)
    return false;
  if (root -> lock == false)
    return true;
  propogate(root, -1);
  root -> lock = false;
  return true;
}
bool isLock(node * root) {
  return root -> lock;
}
void parent(node * root, node * pa) {
  if (root == NULL)
    return;
  root -> parent = pa;
  parent(root -> left, root);
  parent(root -> right, root);
}
int main(void) {
  node * root = NULL;
  root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  node * arr[7];
  arr[0] = root;
  arr[1] = root -> left;
  arr[2] = root -> right;
  arr[3] = root -> left -> left;
  arr[4] = root -> left -> right;
  arr[5] = root -> right -> left;
  arr[6] = root -> right -> right;
  int query;
  parent(root, NULL);
  cin >> query;
  int x, y;
  cout << "Till 6" << endl;
  for (int i = 0; i < query; i++) {
    cout << "0 for unlock \n1 for checking\n2 for calling" << endl;
    cin >> x >> y;
    if (x == 0)
      cout << "Unlocking " << Unlock(arr[y]) << endl;
    else if (x == 1)
      cout << "cheking lock " << isLock(arr[y]) << endl;
    else
      cout << "Calling Lock " << Lock(arr[y]) << endl;
  }

}