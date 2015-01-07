#include<iostream>
#include"../treenode.h"

using namespace std;

/*
 * Recurrsion method
 */
void traversal(TreeNode *root, vector<int> &res){
	if(root){
		postorderTraversal_recurr(root->left);
		postorderTraversal_recurr(root->right);
		res.push_back(root->val);
	}
}

vector<int> postorderTraversal_recurr(TreeNode *root) {
	vector<int> res;
	traversal(root,res);
	return res;
}

/*
 * Iteration method
 */
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> res;
	stack<TreeNode *> st;
	TreeNode *curr = root, *prev = nullptr;

	while(!st.empty() || curr){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}else{
			curr = st.top();

			if(prev == curr->right || !curr->right){
				//visit curr
				res.push_back(curr->val);
				st.pop();
				prev = curr;
				curr = nullptr;
			}else{
				curr = curr->right;
			}
		}
	}

	return res;
}

/*
 * Mirror
 */
