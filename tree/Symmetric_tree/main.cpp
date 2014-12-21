#include<iostream>
using namespace std;

/*
 * Symmetric tree -- Recurrsion
 * Just compare !
 */
bool validate(TreeNode *left,TreeNode *right){
	if(left == nullptr && nullptr == right)
		return true;

	return (left->val==right->val && validate(left->left,right->right) && validate(left->right,right->left);
}
bool isSymmetric(TreeNode *root){
	if(nullptr == root) 
		return true;
	return root->left && root->right && validate(root->left,root->right);
}
