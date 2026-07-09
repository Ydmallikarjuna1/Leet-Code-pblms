#include <iostream>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


bool isMirror(TreeNode* leftTree, TreeNode* rightTree) 
{
    
    if (leftTree == NULL && rightTree == NULL)
        return true;

   
    if (leftTree == NULL || rightTree == NULL)
        return false;

   
    return (leftTree->data == rightTree->data) &&
           isMirror(leftTree->left, rightTree->right) &&
           isMirror(leftTree->right, rightTree->left);
}


bool isSymmetric(TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
   

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;

    return 0;
}