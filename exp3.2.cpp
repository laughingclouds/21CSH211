#include <iostream>

class BST {
public:
  int data;
  BST *left = NULL, *right = NULL;
};
BST *insert(BST *root, int value) {
  if (!root) {
    BST *newNode = new BST();
    newNode->data = value;
    return newNode;
  }
  if (value > root->data) {
    root->right = insert(root->right, value);
  } else if (value < root->data) {
    root->left = insert(root->left, value);
  }
  return root;
}
BST *search(BST *root, int val) {
  if (root == NULL || root->data == val)
    return root;
  if (root->data < val)
    return search(root->right, val);
  return search(root->left, val);
}
void inorder(BST *root) {
  if (!root) {
    return;
  }
  inorder(root->left);
  std::cout << root->data << '\n';
  inorder(root->right);
}
int main() {
  int n;
  std::cout << "enter number of elements in BST: ";
  std::cin >> n;
  BST *root = NULL;
  std::cout << "enter elements of BST: \n";
  for (int i = 0; i < n; i++) {
    int elem;
    std::cin >> elem;
    root = insert(root, elem);
  }
  std::cout << "Elements of BST are: \n";
  ;
  inorder(root);
  int val;
  std::cout << "Enter value for search: ";
  std::cin >> val;
  BST *key = search(root, val);
  if (key) {
    std::cout << "element found " << key->data << '\n';
  } else {
    std::cout << "sorry not in the bst\n";
  }
  return 0;
}